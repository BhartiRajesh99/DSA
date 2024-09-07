#include<iostream>
#include<vector>
using namespace std;

constexpr int INFINITY = 9999;
constexpr int NIL = -1;
constexpr int TEMP = 0;
constexpr int PERMANENT = 1;

struct MST{
    int u;
    int v;
};
class Graph{
    private:
        vector<vector<int>> adj;
        vector<int> EdgeLength;
        vector<bool> status;
        vector<int> predecessor;
        int vertex;
    public:
        Graph(int);
        int minEdgeLengthVertex();
        void displayAdjacancyMatrix();
        void Prims(int);
        void createGraph();
};

Graph::Graph(int vertex){
    this->vertex = vertex;
    adj.resize(vertex + 1);
    for(auto &i: adj){
        i.resize(vertex + 1);
        i.assign(i.size(), 0);
    }
    EdgeLength.resize(vertex + 1);
    EdgeLength.assign(EdgeLength.size(), INFINITY);
    status.resize(vertex + 1);
    status.assign(status.size(), TEMP);
    predecessor.resize(vertex + 1);
    predecessor.assign(predecessor.size(), NIL);
}


void Graph::createGraph(){
    int u,v,weight;
    int maxEgde = ( vertex * (vertex-1)) / 2; //for undirected graph
    for(int i=1; i<=maxEgde; i++){
        cout<<"Enter source and destination enter(-1 -1) to stop: ";
        cin>>u>>v;
        if(u == -1 && v == -1)
            break;
        cout<<"Enter weight: ";
        cin>>weight;
        if(u<1 || u>vertex || v<1 || v>vertex){
            cout<<"Invalid edge"<<endl;
            i--;
        }
        else{
            adj[u][v] = weight;
            adj[v][u] = weight;
        }
    }
}

int Graph::minEdgeLengthVertex(){
    int k = NIL;
    int min = INFINITY;
    for(int i = 1; i<=vertex; i++){
        if(status[i] == TEMP && min > EdgeLength[i]){
            min = EdgeLength[i];
            k = i;
        }
    }
    return k;
}

void Graph::Prims(int source){
    int current;
    int count=0; // minimum spanning tree edge count
    int totalWeight = 0; // total weight of MST
    MST spanningTree[vertex+1];

    EdgeLength[source] = 0;
    while(1){
        current = minEdgeLengthVertex();
        if(current == NIL){
            if(count == vertex-1)
                break;
            else{ //if count less than vertex-1
                cout<<"Graph is disconnected, Spanning tree is not possible"<<endl;
                return;
            }
        }
        status[current] = PERMANENT;

        //creating edges of MST
        if(current != source){
            count++;
            spanningTree[count].u = predecessor[current];
            spanningTree[count].v = current;
        }

        for(int i=1; i<=vertex; i++){
            if(adj[current][i] != 0 && status[i] == TEMP)
                if(adj[current][i] < EdgeLength[i]){
                    predecessor[i] = current;
                    EdgeLength[i] = adj[current][i];
                }
        }
    }

    //print edges of MST
    for(int i=1; i<vertex; i++){
        cout<<spanningTree[i].u<<"->"<<spanningTree[i].v<<endl;
        totalWeight += adj[spanningTree[i].u][spanningTree[i].v];
    }

    cout<<"Total weight of MST: "<<totalWeight<<endl;
}


void Graph::displayAdjacancyMatrix(){
    for(int i=1; i<adj.size(); i++){
        for(int j=1; j<adj.size(); j++)
            cout<<adj[i][j]<<" ";
        cout<<endl;
    }
}

//driver code
int main(int argc, char* argv[]){
    int vertex;
    cout<<"Enter number of vertex: ";
    cin>>vertex;
    Graph g(vertex);
    g.createGraph();
    g.displayAdjacancyMatrix();
    g.Prims(2);
    return 0;
}