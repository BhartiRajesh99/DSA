#include<iostream>
#include<list>
#include<stack>
#include<queue>
using namespace std;
class Graph{
    private:
        int vertex,directed=0;
        vector<list<int>> adj;
        bool *visited=nullptr;
    public:
        Graph(int vertex){
            this->vertex = vertex;
            adj.resize(vertex + 1);
            visited = new bool[vertex+1]{false};
        }
        void addEdge(int u, int v){
            adj[u].push_back(v);
            if(!this->directed)
                adj[v].push_back(u);
        }
        void printGraph(){
            for(int i=1; i<adj.size(); i++){
                cout<<i<<"-> ";
                for(auto j: adj[i]){
                    cout<<j<<" ";
                }
                cout<<endl;
            }
        }
        //DFS using recursion
        void DFS(int v){
            cout<<v<<" ";
            visited[v] = true;
            for(auto i: adj[v])
                if(!visited[i])
                    DFS(i);
        }
        //DFS using stack
        void DFS_Stack(int v){
            bool visit[vertex+1] = {false};
            stack<int>s;
            s.push(v);
            cout<<s.top()<<" ";
            visit[s.top()] = true;
            while(!s.empty()){
                int flag = 0;
                for(auto i: adj[s.top()]){
                    if(!visit[i]){
                        flag = 1;
                        s.push(i);
                        cout<<s.top()<<" ";
                        visit[i] = true;
                    }
                }
                if(!flag)
                    s.pop();
            }
        }
        //BFS using queue
        void BFS(int v){
            queue<int> q;
            int visit[vertex+1] = {false};
            q.push(v);
            visit[q.front()] = true;
            while(!q.empty()){
                for(auto i: adj[q.front()]){
                    if(!visit[i]){
                        q.push(i);
                        visit[i] = true;
                    }
                }
                cout<<q.front()<<" ";
                q.pop();
            }
        }
};
int main(){
    Graph g(6);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,1);
    g.addEdge(4,1);
    g.addEdge(4,5);
    g.addEdge(4,2);
    g.addEdge(3,5);
    g.addEdge(5,1);
    g.addEdge(6,1);
    g.printGraph();
    cout<<"DFS: ";
    g.DFS(4);
    cout<<endl;
    cout<<"DFS: ";
    g.DFS_Stack(1);
    cout<<endl;
    cout<<"BFS: ";
    g.BFS(4);
    return 0;
}