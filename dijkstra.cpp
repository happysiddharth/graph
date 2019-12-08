#include<iostream>
using namespace std;
#define v 4
//find minimun distance vertex
int minDistanceVertex(int distance[],bool visited[]){
 int min = INT_MAX, min_index=0; 

    for (int i = 0; i < v; i++) 
        if (visited[i] == false && distance[i] <= min) 
            min = distance[v], min_index = i; 
  
    return min_index; 
}
//print the graph

void printGraph(int distance[]){
	 printf("Vertex \t\t Distance from Source\n"); 
    for (int i = 0; i < v; i++) 
        printf("%d \t\t %d\n", i, distance[i]); 
}

void dijkstraAlgo(int graph[v][v],int src){
	bool visited[v];
	int distance[v];
	for (int i = 0; i < v; i++) 
        distance[i] = INT_MAX, visited[i] = false;

	distance[src]=0;
	
	for(int i=0;i<(v)-1;i++){
		int u = minDistanceVertex(distance,visited);
		visited[u]=true;
		for(int j=0;j<v;j++){
			if(!visited[j] and graph[u][j] and distance[u]!=INT_MAX and distance[j]>graph[u][j]+distance[u]){
				distance[j]=graph[u][j]+distance[u];
			}
		}

	}
	printGraph(distance);
	
	
}


int main() 
{ 
    
    int graph[v][v] = { {0,5,-6,1},{5,0,5,1},{-6,5,0,1}}; 
  
    dijkstraAlgo(graph, 0); 
 

    return 0; 
} 
