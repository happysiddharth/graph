#include <bits/stdc++.h>

using namespace std;


 int cost;
 int color_array[1000];
 int color_to_find;
 class Graph{

     map<int,list<int>> edge;
     public:
     void addEdge(int u,int v){
         edge[u].push_back(v);
         edge[v].push_back(u);
     }
     void bfs(int i){
         vector<bool> visited;
         queue<pair<int,int>> q;
         pair<int ,int> p;
         q.push({i,0});
         visited[i]=1;
         while(!q.empty()){
             p = q.front();
             q.pop();
             for(auto neighbour:edge[p.first]){
                 if(!visited[p.first]){
                     if(color_array[neighbour]==color_to_find){
                         cost = p.second+1;
                         return;
                     }
                     visited[neighbour]=1;
                     q.push({neighbour,p.second+1});
                 }
             }
         }
     }

 };

int main()
{
  int node,edges;
  cin>>node>>edges;
  Graph ob;
  int u,v;
  for(int i=0;i<edges;i++){
      cin>>u>>v;
      ob.addEdge(u,v);
  }

  for(int i=0;i<=node;i++){
      cin>>color_array[i];
  }

  cin>>color_to_find;
  int ans=INT_MAX;
  for(int i=0;i<node;++i){
      if(color_array[i]==color_to_find){
          cost=INT_MAX;
          ob.bfs(i);
          ans=min(ans,cost);
      }
  }
  if(ans==INT_MAX){
      cout<<-1;
  }else{
      cout<<ans;
  }

}
