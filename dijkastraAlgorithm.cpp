#include<iostream>
#include<vector>
#include<list>
constexpr int TEMP = 0;
constexpr int INFINITY = 99999;
constexpr int PERMANENT = 1;
using namespace std;
class Graph{
    private:
        vector<int> pathLength;
        vector<vector<int>> adj;
        vector<int> status;
        vector<int> predecessor;
    public:
        Graph(int vertex){
            adj.resize(vertex+1);
            for(auto i=adj.begin(); i!=adj.end(); i++){
                i->resize(vertex+1);
                for(auto j: *i)
                    j = 0;
            }
            pathLength.resize(vertex+1);
            //initialisation of path length with infinity
            pathLength.assign(pathLength.size(), INFINITY);
            status.resize(vertex+1);
            //initialisation of status with 0
            status.assign(status.size(), TEMP);
            predecessor.resize(vertex+1);
            //initialisation of predecessor with -1
            predecessor.assign(predecessor.size(), -1);
        }

        void addEdge(int u, int v, int w){
            if(u<=0 || u>=adj.size() || v<=0 || v>=adj.size()){
                cout<<"invalid egde"<<endl;
                return;
            }
            adj[u][v] = w;
        }

        int min_temp(){
            int k = -1;
            int min = INFINITY;
            for(int i=1; i<adj.size(); i++){
                if(status[i] == TEMP && pathLength[i] < min){
                    min = pathLength[i];
                    k = i;
                }
            }
            return k;
        }

        void dijkastra(int source){
            if(source<=0 || source>=adj.size()){
                cout<<"invalid source or destination"<<endl;
                return;
            }
            int current;
            pathLength[source] = 0;
            while(1){
                current = min_temp();
                if(current == -1)
                    return;
                status[current] = PERMANENT;

                for(int i=1; i<adj.size(); i++){
                    if(adj[current][i] != 0 && status[i] == TEMP)
                        if(pathLength[current] + adj[current][i] < pathLength[i]){
                            predecessor[i] = current;
                            pathLength[i] = pathLength[current] + adj[current][i];
                        }
                }
            }
        }

        void diaplayMatrix(){
            for(int i=1; i<adj.size(); i++){
                for(int j=1; j<adj.size(); j++)
                    cout<<adj[i][j]<<" ";
                cout<<endl;
            }
        }

        void findPath(int s, int v){
            vector<int> path;
            path.resize(adj.size());
            int u,count = 0;
            int shortestDistance = 0;
            
            while(v != s){
                count++;
                path[count] = v;
                u = predecessor[v];
                if(u == -1){
                    cout<<"Invalid Path";
                    return;
                }
                shortestDistance += adj[u][v];
                v = u;
            }
            count++;
            path[count] = s;
            cout<<"Shortest Path is: ";
            for(int i=count; i>=1; i--)
                cout<<path[i]<<"->";
            cout<<endl;
            cout<<"Shortest Diatance: "<<shortestDistance<<endl;
        }
};
int main(int argc, char* argv[]){
    Graph g(5);
    g.addEdge(1,2,2);
    g.addEdge(1,3,1);
    g.addEdge(2,3,4);
    g.addEdge(2,4,3);
    g.addEdge(3,5,3);
    g.addEdge(2,5,5);
    g.addEdge(4,5,2);
    g.diaplayMatrix();
    g.dijkastra(1);
    g.findPath(1,5);
    return 0;
}