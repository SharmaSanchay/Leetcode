//Leetcode -> 502 (https://leetcode.com/problems/ipo/)
class Solution {
public:
    // Custom comparator function to sort pairs based on the first element (capital)
    bool static comp(pair<int, int>& a, pair<int, int>& b) {
        return a.first < b.first;
    }
    
    // Function to find the maximized capital
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // Min-heap to store projects based on their capital requirement
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // Push all projects into the min-heap
        for (int i = 0; i < profits.size(); i++) {
            pq.push({capital[i], profits[i]});
        }
        
        // Max-heap to store available projects based on their profit
        priority_queue<int> pq2;
        
        // Perform k iterations to maximize capital
        while (k--) {
            // Transfer all projects that can be completed with current capital (w) to the max-heap
            while (pq.size() && pq.top().first <= w) {
                pq2.push(pq.top().second); // Push the profit
                pq.pop();
            }
            
            // If there are available projects, complete the one with the highest profit
            if (pq2.size()) {
                w += pq2.top(); // Increase capital by the profit of the chosen project
                pq2.pop();
            }
        }
        
        return w; // Return the maximized capital after k projects
    }
};
/*
Time Complexity->O(NLogN+KLogN)
Space Complexity->O(N)
*/
