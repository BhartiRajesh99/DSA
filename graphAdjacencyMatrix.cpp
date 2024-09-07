#include<iostream>
using namespace std;
class Graph{
    private: 
        int adj[20][20] = {0};
        int vertex,Edges,directed;
    public:
        // for unweighted graph
        void addEdge(int u, int v){
            adj[u][v] = 1;
            if(this->directed)
                adj[v][u] = 1;
        }
        //for weighted graph
        void addEdge(int u, int v, int weight){
            adj[u][v] = weight;
            if(this->directed)
                adj[v][u] = weight;
        }
        void createGraph(int V,int E){
            if(V>=30 || E > (V*(V-1))/2){
                cout<<"Invalid number of vertex or edges"<<endl;
                return;
            }
            cout<<"Enter 0 for directed and 1 for undirected graph:";
            cin>>this->directed;
            vertex = V;
            Edges = E;
            int u,v;
            for(int i=1; i<E; i++){
                cout<<"Enter source and destination for "<<i+1<<" edge:";
                cin>>u>>v;
                if(u<=V && v<=V && V<30) 
                    addEdge(u,v);
                else
                    cout<<"Invalid Edge"<<endl;
            }
        }
        void printAdjacencyMatrix(){
            for (int i = 1; i <= vertex; i++){
                for(int j = 1; j<= vertex; j++)
                    cout<<adj[i][j]<<" ";
                cout<<endl;
            }
        }
};
int main(){
    Graph g;
    int v,e;
    cout<<"Enter the number of vertex and edges:";
    cin>>v>>e;
    g.createGraph(v,e);
    g.printAdjacencyMatrix();
    return 0;
}