//Leetcode->2254(https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/)
class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int> st;  // A set to store banned numbers within the range [1, n]
        
        // Insert banned numbers into the set if they are within the range [1, n]
        for (auto val : banned) {
            if (val <= n) {
                st.insert(val);
            }
        }
        
        int cnt = 0;  // Counter for the number of non-banned numbers
        int sum = 0;  // Sum of the selected non-banned numbers
        
        // Iterate through numbers from 1 to n
        for (int i = 1; i <= n; i++) {
            // Skip the number if it is in the banned set
            if (st.find(i) != st.end()) {
                continue;
            }
            // If adding the current number doesn't exceed maxSum, add it to the sum and increment count
            if (sum + i <= maxSum) {
                sum += i;
                cnt++;
            } else {
                break;  // Stop if adding the next number would exceed maxSum
            }
        }
        
        return cnt;  // Return the count of selected non-banned numbers
    }
};
/*
Time Complexity->O(N)
Space Complexity->O(N)
*/
