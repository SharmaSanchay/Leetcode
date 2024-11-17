//Leetcode -> 862 (https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/description/)
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
    int n = nums.size();
    vector<long long> prefix(n + 1, 0);
    
    // Step 1: Compute the prefix sum array
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + nums[i];
    }
    
    // Step 2: Monotonic deque
    deque<int> dq;
    int minLength = INT_MAX;
    
    // Traverse through the prefix sum array
    for (int i = 0; i <= n; ++i) {
        // Step 3: Check for valid subarrays using the deque
        while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k) {
            minLength = min(minLength, i - dq.front());
            dq.pop_front();  // Remove the front of the deque
        }
        
        // Step 4: Maintain a monotonic deque
        while (!dq.empty() && prefix[i] <= prefix[dq.back()]) {
            dq.pop_back();  // Pop elements from the back that are not useful
        }
        
        dq.push_back(i);  // Push the current index into the deque
    }
    
    // Step 5: Return the result
    return minLength == INT_MAX ? -1 : minLength;
}
};
/*
Time Complexity-> O(N)
Space Complexity->O(N)
*/