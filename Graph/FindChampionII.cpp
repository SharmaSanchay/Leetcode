//Leetcode->2924 (https://leetcode.com/problems/find-champion-ii/description/)
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        // Initialize an array to keep track of the in-degrees of each node
        vector<int> indegree(n, 0);
        
        // Iterate through each edge and increment the in-degree of the destination node
        for(vector<int>& edge : edges){
            int u = edge[0]; // Source node
            int v = edge[1]; // Destination node
            indegree[v]++;
        }
        
        int CntChamp = 0; // Counter for nodes with zero in-degrees
        int nameChamp = 0; // Potential champion node
        
        // Iterate through the in-degree array to find nodes with zero in-degrees
        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] == 0){
                nameChamp = i; // Store the node with zero in-degrees
                CntChamp++; // Increment the counter
                
                // If more than one node has zero in-degrees, return -1
                if(CntChamp > 1){
                    return -1;
                }
            }
        }
        
        // Return the name of the champion node
        return nameChamp;
    }
};
/*
Time Complexity->O(M+N)
Space Complexity->O(N)
*/
