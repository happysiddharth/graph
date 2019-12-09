#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;

template<typename T>

class Graph{
    map<T,list<T>> adj;
public:
     void addEdge(T u,T v,bool isBirectional=false){
        adj[u].push_back(v);
        if(isBirectional){
            adj[v].push_back(u);
        }
    }
    void topologicalSort(){

        queue<T> que;
        map<T,int> indegree;
        for(auto a:adj){
            indegree[a.first]=0;

        }
        for(auto a:adj){
            T node = a.first;
            for(auto neighbour:adj[node]){
                indegree[neighbour]+=1;
            }
        }
        for(auto a:adj){
            T node = a.first;
            if(indegree[node]==0){
                que.push(node);
            }
        }
        while(!que.empty()){
            T node = que.front();
            que.pop();

            cout<<node<<"->";
            for(auto neighbour:adj[node]){
                indegree[neighbour]--;
                if( indegree[neighbour]==0){
                    que.push(neighbour);
                }
            }
        }
    }
};
int main(){
	Graph<string> g;
    g.addEdge("english","programming logic");
    g.addEdge("maths", "programming logic");
    g.addEdge("programming logic","html");
    g.addEdge("programming logic","python");
    g.addEdge("programming logic","java");
    g.addEdge("programming logic","js");
    g.addEdge("python","wd");
    g.addEdge("html","css");
    g.addEdge("css","js");
    g.addEdge("js","wd");
    g.addEdge("java","wd");
    g.addEdge("python","wd");







	g.topologicalSort();
	return 0;
}

