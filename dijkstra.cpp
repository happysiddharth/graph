#include<iostream>
using namespace std;
#define v 9
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
	
	for(int i=0;i<v-1;i++){
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
    
    int graph[v][v] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
  
    dijkstraAlgo(graph, 0); 
 

    return 0; 
} 
