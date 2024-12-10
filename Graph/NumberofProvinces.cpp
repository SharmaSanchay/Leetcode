//Leetcode -> 547 (https://leetcode.com/problems/number-of-provinces/description/)
class Solution {
public:
    // Depth-First Search (DFS) function to explore all connected nodes
    void dfs(vector<vector<int>>& adj, int node, vector<bool>& visited) {
        visited[node] = true; // Mark the current node as visited
        for (int i = 0; i < adj.size(); i++) { // Iterate through all nodes
            // Check if there is an edge from the current node to node i and if node i has not been visited
            if (adj[node][i] == 1 && !visited[i]) {
                dfs(adj, i, visited); // Recursively visit the connected node
            }
        }
    }

    // Function to find the number of provinces (connected components) in the graph
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size(), false); // Initialize the visited vector
        int cnt = 0; // Initialize the count of provinces

        // Iterate through all nodes
        for (int i = 0; i < isConnected.size(); i++) {
            if (!visited[i]) { // If the node has not been visited
                cnt++; // Increment the province count
                dfs(isConnected, i, visited); // Perform DFS for the current node
            }
        }

        return cnt; // Return the number of provinces
    }
};
/*
Time Complexity->O(V^2)
Space Complexity->O(V)
*/
