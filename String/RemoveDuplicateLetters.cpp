//Leetcode->316(https://leetcode.com/problems/remove-duplicate-letters/)
class Solution {
public:
    string removeDuplicateLetters(string s) {
        // Vector to track if a character has been added to the result
        vector<bool> taken(26, false);
        
        // Vector to store the last index of each character in the string
        vector<int> lastindex(26, 0);
        
        // Populate the lastindex vector with the last occurrence of each character
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            lastindex[ch - 'a'] = i;
        }
        
        // String to store the result
        string result = "";
        
        // Iterate through the string
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            int idx = ch - 'a';
            
            // If the character is already taken, skip it
            if (taken[idx] == true) {
                continue;
            }
            
            // Ensure the result is in lexicographical order and pop characters that can be placed later
            while (result.length() > 0 && result.back() > ch && lastindex[result.back() - 'a'] > i) {
                taken[result.back() - 'a'] = false;
                result.pop_back();
            }
            
            // Add the current character to the result and mark it as taken
            result += ch;
            taken[idx] = true;
        }
        
        // Return the result string
        return result;
    }
};
/*
Time Complexity->O(N)
Space Complexity->O(1)
*/
