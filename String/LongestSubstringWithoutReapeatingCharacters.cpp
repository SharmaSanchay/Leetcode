//leetcode->3 (https://leetcode.com/problems/longest-substring-without-repeating-characters/description/)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Initialize a vector to store the last seen index of each character (256 possible characters)
        vector<int> mpp(256, -1);

        int r = 0, l = 0;     // Initialize pointers for the right and left boundaries of the window
        int maxlen = 0;       // Initialize the maximum length of the substring

        // Iterate over the string using the right pointer
        while (r < s.length()) {
            // If the character at position 'r' has been seen before and is within the current window
            if (mpp[s[r]] != -1) {
                // Update the left boundary to exclude the last occurrence of the current character
                if (mpp[s[r]] >= l) {
                    l = mpp[s[r]] + 1;
                }
            }

            // Calculate the current length of the window
            int len = r - l + 1;

            // Update the maximum length if the current length is greater
            maxlen = max(maxlen, len);

            // Update the last seen index of the current character
            mpp[s[r]] = r;

            // Move the right boundary to the next position
            r++;
        }

        // Return the maximum length of the substring without repeating characters
        return maxlen;
    }
};
/*
Time Complexity->O(N)
Space Complexity->O(1)
*/
