#include<iostream>
#include<map>
#include<list>
using namespace std;
template<typename T>
class Graph{
    map<T,list<T>> edge;
public:
    void addEdge(T u,T v,bool isBirectional=false){
        edge[u].push_back(v);
        if(isBirectional){
            edge[v].push_back(u);
        }
    }
    void topologicalSortHelper(map<T,bool> &visited,list<T> &ans,T src){
        visited[src] = true;
        for(auto a:edge[src]){
            if(visited[a]==false){
                topologicalSortHelper(visited,ans,a);
            }
        }
        ans.push_front(src);

    }
    void topologicalSort(){
        map<T,bool> visited;
        list<T> ans;
        for(auto a:edge){
             if(visited[a.first]==false){
                 topologicalSortHelper(visited,ans,a.first);
             }

        }

        for(auto a:ans){
            cout<<a<<"->";
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
