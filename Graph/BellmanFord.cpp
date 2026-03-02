// problem link -> https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int>dist(V,1e8);
        dist[src] = 0;
        for(int i=0;i<=V-1;i++){
            for(auto edge:edges){
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                
                if(dist[u]!=INT_MAX && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }
        
        // now we detect the negative cycle
        
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if(dist[u]!=INT_MAX && dist[u] + wt < dist[v]){
                return {-1};
            }
        }
        return dist;
    }
};
