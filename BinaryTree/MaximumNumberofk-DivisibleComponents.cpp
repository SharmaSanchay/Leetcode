//Leetcode->2872(https://leetcode.com/problems/maximum-number-of-k-divisible-components/description/)
class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        // If the number of nodes is less than 2, return 1 (base case)
        if (n < 2) return 1;
        int ans = 0;

        // Create an adjacency list for the graph and a vector to store the in-degrees of nodes
        vector<vector<int>> g(n);
        vector<int> in(n, 0);

        // Build the graph and update the in-degrees
        for (auto edge : edges) {
            int node1 = edge[0], node2 = edge[1];
            g[node1].push_back(node2);
            g[node2].push_back(node1);
            in[node1]++;
            in[node2]++;
        }

        // Convert the values vector to long long to avoid overflow
        vector<long long> longvalues(values.begin(), values.end());

        // Use a queue to perform a topological sort
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (in[i] == 1) q.push(i); // Push all leaf nodes (nodes with in-degree 1) to the queue
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            in[curr]--; // Decrease in-degree of the current node

            // Calculate the carry value. If the current value is divisible by k, carry is 0; otherwise, it is the current value
            long long carry = (longvalues[curr] % k == 0) ? 0 : longvalues[curr];
            if (carry == 0) ans++; // Increment ans if carry is 0

            // Traverse the neighbors of the current node
            for (int ng : g[curr]) {
                if (in[ng] > 0) {
                    in[ng]--;
                    longvalues[ng] += carry; // Add carry to the neighbor's value
                    if (in[ng] == 1) q.push(ng); // Push the neighbor to the queue if it becomes a leaf node
                }
            }
        }

        return ans; // Return the number of k-divisible components
    }
};
/*
Time Complexity->O(n+m)
Space Complexity->O(n+m)
*/
