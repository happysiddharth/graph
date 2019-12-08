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
		void printGraph(){
			for(auto i:edge){
				cout<<i.first<<"->";
				for(auto j:i.second){
					cout<<j<<"->";
				}
				cout<<"\n";
			}
		}
		void bfs(T src){
		    queue<T> q;
		    map<T,bool> visited;
		    q.push(src);
		    visited[src] = 1;
		    while(!q.empty()){
		        T front = q.front();
		        cout<<front<<"->";
		        q.pop();
		        for(auto a:edge[front]){
		            if(visited[a]!=1){
		                visited[a]=1;
		                q.push(a);
		            }
		        }
		    }
		}
		
	
		void dfs(T src){
		   stack<T> stk;
		   stk.push(src);
		   
		   map<T,bool> visited;
		   
		   while(!stk.empty()){
		       T top = stk.top();
		       stk.pop();
		       
		       if(!visited[top]){
		           cout<<top<<"->";
		           visited[top]=true;
		       }
		       
		       for(auto a:edge[top]){
		           if(!visited[a]){
		               stk.push(a);
		           }
		       }
		       
		   }
		}
		
		~Graph(){
	
		}
};
int main(){
	Graph<int> g;
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
	

	g.dfs(2);
	return 0;
}
