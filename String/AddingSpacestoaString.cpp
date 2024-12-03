// Leetcode->2109 (https://leetcode.com/problems/adding-spaces-to-a-string/description/)
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int i = 0, sp = 0;
        string ans = "";
        
        // Iterate through the string 's' and the 'spaces' vector simultaneously
        while (i < s.length() && sp < spaces.size()) {
            // Append the substring from current position 'i' to the position 'spaces[sp]'
            ans += s.substr(i, spaces[sp] - i) + " ";
            // Move the current position 'i' to the position specified in 'spaces[sp]'
            i = spaces[sp];
            // Move to the next space index
            sp++;
        }
        
        // If there are remaining characters in the string 's' after the last space
        if (i < s.length()) {
            // Append the remaining substring to 'ans'
            ans = ans + s.substr(i);
        }
        
        // Return the final string with spaces added
        return ans;
    }
};
/*
Time Complexity->O(n+m)
Space Complexity->O(n+m)
*/
