//Leetcode->2337(https://leetcode.com/problems/move-pieces-to-obtain-a-string/description/)
class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.length();  // Get the length of the string
        int i = 0, j = 0;  // Initialize two pointers for start and target strings
        
        // Iterate through both strings
        while (i < n || j < n) {
            // Skip '_' characters in the start string
            while (i < n && start[i] == '_') {
                i++;
            }
            
            // Skip '_' characters in the target string
            while (j < n && target[j] == '_') {
                j++;
            }
            
            // If either pointer reaches the end, check if both have reached the end
            if (i == n || j == n) {
                return i == n && j == n;  // Both should be at the end for a valid transformation
            }
            
            // If characters at current pointers do not match, return false
            if (start[i] != target[j]) return false;
            
            // Check for invalid moves of 'L' and 'R'
            if (start[i] == 'L' && i < j) {
                return false;  // 'L' can only move to the left, so i should be >= j
            }
            if (start[i] == 'R' && i > j) {
                return false;  // 'R' can only move to the right, so i should be <= j
            }
            
            // Move both pointers forward
            i++;
            j++;
        }
        
        return true;  // If all checks pass, return true
    }
};
/*
Time Complexity->O(N)
Space Complexity->O(1)
*/
