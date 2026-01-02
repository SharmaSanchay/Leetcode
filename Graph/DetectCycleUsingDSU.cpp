//question link  -> (https://www.geeksforgeeks.org/problems/detect-cycle-using-dsu/1)
class Solution {
    public:
       vector<int> parent;
      vector<int> rank;

      int find(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = find(parent[node]);
    }
      void Union(int u,int v){
          int parent_u = find(u);
          int parent_v = find(v);
          if(parent_u == parent_v){
              return ;
          }
          if(rank[parent_u] > rank[parent_v]){
              parent[parent_v] = parent_u;
          }else if(rank[parent_u] < rank[parent_v]){
              parent[parent_u] = parent_v;
          }else{
              parent[parent_u] = parent_v;
              rank[parent_v]++;
          }
      }
      int detectCycle(int V, vector<int> adj[]) {
           parent.resize(V);
          rank.resize(V, 0);
           for(int i = 0; i<V; i++)
              parent[i] = i;
          for(int u=0;u<V;u++){
              for(auto v:adj[u]){
                  if(u<v){
                      int parent_u = find(u);
                      int parent_v = find(v);
                      if(parent_u == parent_v){
                          return 1;
                      }else{
                          
                      Union(u,v);
                      }
                  }
              }
          }
          return 0;
          
      }
  };