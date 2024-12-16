//Leetcode ->131(https://leetcode.com/problems/palindrome-partitioning/description/)
class Solution {
public:
    // Function to check if a given string is a palindrome
    bool isPandil(string str) {
        int s = 0, e = str.length() - 1;
        while (s <= e) {
            if (str[s] != str[e]) {
                return false; // If characters at start and end don't match, it's not a palindrome
            }
            s++;
            e--;
        }
        return true; // If all characters match, it's a palindrome
    }

    // Recursive function to find all palindromic partitions of the given string
    void getallparts(string s, vector<string>& partitions, vector<vector<string>>& ans) {
        if (s.size() == 0) {
            ans.push_back(partitions); // If the string is empty, add the current partition to the result
            return;
        }
        for (int i = 0; i < s.length(); i++) {
            string part = s.substr(0, i + 1); // Take the substring from the start to the current position
            if (isPandil(part)) { // Check if the substring is a palindrome
                partitions.push_back(part); // Add the palindrome substring to the current partition
                getallparts(s.substr(i + 1), partitions, ans); // Recursively process the remaining string
                partitions.pop_back(); // Backtrack and remove the last added substring
            }
        }
    }

    // Main function to partition the string into all possible palindromic substrings
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans; // Vector to store the result
        vector<string> partitions; // Vector to store the current partition
        getallparts(s, partitions, ans); // Start the recursive partitioning
        return ans; // Return the result
    }
};
/*
Time Complexity->O(N*2^N)
Space Complexity->O(N)
*/
