//Leetcode -> 1014(https://leetcode.com/problems/best-sightseeing-pair/description/)
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        // Initialize a vector to store the maximum values up to each index
        vector<int> ans(values.size(), -1);

        // Variable to store the maximum value of (values[i] + i) seen so far
        int maxi = INT_MIN;

        // First pass to calculate the maximum (values[i] + i) for each index
        for (int i = 0; i < values.size(); i++) {
            maxi = max(maxi, values[i] + i);  // Update maxi with the maximum value of (values[i] + i)
            ans[i] = maxi;  // Store the current maximum value in ans[i]
        }

        // Variable to store the result, i.e., the maximum score of a sightseeing pair
        int res = INT_MIN;

        // Second pass to calculate the result using the stored values in ans
        for (int i = 1; i < values.size(); i++) {
            res = max(res, ans[i-1] + (values[i] - i));  // Calculate the score and update res with the maximum value
        }

        // Return the result, i.e., the maximum score of a sightseeing pair
        return res;
    }
};
/*
Time Complexity->O(N)
Space Complexity->O(N)
*/
