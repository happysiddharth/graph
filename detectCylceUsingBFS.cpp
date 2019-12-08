#include<iostream>
#include<list>
using namespace std;
class Graph{
	int n;
	list<int> *edge;
	public:
		Graph(int nodes){
			n = nodes;
			edge = new list<int>[nodes];
		}
		void addEdge(int u ,int v,bool isDirected = true){
			edge[u].push_back(v);
			if(isDirected){
				edge[v].push_back(u);
			}
		}
		
		void printGraph(){
		
			for(int i=0;i<n;i++){
			    cout<<i<<"->";
			    for(auto a:edge[i]){
			    	cout<<a<<"->";
				}		
				cout<<endl;
			}
		}
		~Graph(){
			delete edge;
		}
	
};
int main(){
	Graph graph1(3);
	graph1.addEdge(0,1);
	graph1.addEdge(1,2);
	graph1.addEdge(2,1);
	graph1.printGraph();
	return 0;
}
