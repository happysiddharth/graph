#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<stack>
using namespace std;
template<typename T>
class Graph{
	map<T,list<T> > edge;
	public:
		Graph(){
			
		}
		void addEdge(T u,T v ,bool isbiDirection = false){
			edge[u].push_back(v);
			if(isbiDirection){
				edge[v].push_back(u);
			}
		}
	
		bool isCylce(T src){
		    queue<T> q;
		    map<T,bool> visited;
		    map<T,T> parent;
		    q.push(src);
		    visited[src] = 1;
		    parent[src] = src;
		    while(!q.empty()){
		        T front = q.front();
		       
		        q.pop();
		        for(auto a:edge[front]){
		            if(visited[a]==1 and parent[front]!=a){
		                return true;
		            }else if(visited[a]!=1){
		                q.push(a);
		                parent[a]=front;
		                visited[a]=1;
		                
		            }
		        }
		    }
		    return false;
		}
		
		~Graph(){
	
		}
};
int main(){
	Graph<int> g;
    g.addEdge(0, 1); 
    g.addEdge(1, 2); 
    g.addEdge(2, 2); 
   
  
	

	cout<<g.isCylce(2);
	return 0;
}
