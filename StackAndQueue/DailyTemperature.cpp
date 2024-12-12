//Leetcode->739 (https://leetcode.com/problems/daily-temperatures/)
class Solution {
public:
    // Function to find the number of days until a warmer temperature
    vector<int> dailyTemperatures(vector<int>& nums) {
        vector<int> ans(nums.size(), 0); // Initialize answer vector with zeros
        stack<int> s;                    // Stack to store indices of temperatures
        int i = nums.size() - 1;         // Start from the last day
        
        // Loop through the temperatures from the end to the beginning
        while (i >= 0) {
            if (s.empty()) { // If stack is empty, there is no warmer day in the future
                s.push(i);   // Push the current index onto the stack
                ans[i] = 0;  // No warmer days ahead, so answer is 0
                i--;         // Move to the previous day
            } else {
                if (nums[s.top()] > nums[i]) { // If the top of the stack is warmer
                    int n = s.top() - i;       // Calculate the difference in days
                    ans[i] = n;                // Store the result
                    s.push(i);                 // Push the current index onto the stack
                    i--;                       // Move to the previous day
                } else {
                    s.pop(); // Pop the stack if the top is not warmer
                }
            }
        }
        
        return ans; // Return the result vector
    }
};
/*
Time Complexity->O(N)
Space Complexity->O(N)
*/
