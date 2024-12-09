//Leetcode -> 139 (https://leetcode.com/problems/word-break/description/)
class Solution {
private:
    // Helper function for word break using recursion and memoization
    bool wordBreak(string s, unordered_set<string> &set, vector<int> &memo, int start) {
        // If start index reaches the end of the string, return true (successful segmentation)
        if (start == s.size()) {
            return true;
        }
        
        // If this subproblem has already been solved, return the stored result
        if (memo[start] != -1) {
            return memo[start];
        }
        
        // Try to partition the string and check if each part is a valid word
        for (int i = start; i < s.size(); i++) {
            // If the current substring is in the set and the remaining part can be segmented
            if (set.count(s.substr(start, i + 1 - start)) && wordBreak(s, set, memo, i + 1)) {
                memo[start] = true; // Store the result in the memoization array
                return true; // Return true as the string can be segmented
            }
        }
        
        // Store the result as false in the memoization array and return false
        return memo[start] = false;
    }

public:
    // Main function to check if the string can be segmented into a space-separated sequence of dictionary words
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> memo(s.size(), -1); // Initialize memoization array with -1 (unvisited)
        unordered_set<string> set(wordDict.begin(), wordDict.end()); // Create a set from the word dictionary for quick lookup
        return wordBreak(s, set, memo, 0); // Call the helper function starting from index 0
    }
};
/*
Time Complexity->O(2^N)
Space Complexity->O(N)
*/
