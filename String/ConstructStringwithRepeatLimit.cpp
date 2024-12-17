//Leetcode->2182(https://leetcode.com/problems/construct-string-with-repeat-limit)
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> vec(26, 0); // Vector to count frequency of each character (a-z)
        for (char ch : s) {
            vec[ch - 'a']++; // Increment the frequency of the character
        }

        string result; // The result string to be built
        int i=25;
        while (i >= 0) {
            if (vec[i] == 0) {
                i--;
                continue; // Skip if no characters of this type are left
            }
            char ch = 'a' + i; // Convert index to character
            int freq = min(vec[i], repeatLimit); // Determine how many times to add this character
            result.append(freq, ch); // Append character `freq` times to result
            vec[i] -= freq; // Decrease the count of the character
            
            if (vec[i] > 0) { // If there are still some characters left
                int j = i - 1; // Find the next character to add
                while (j >= 0 && vec[j] == 0) {
                    j--; // Skip characters that are not present
                }
                if (j < 0) { // If no more characters left
                    break;
                }
                result.push_back('a' + j); // Add the next character
                vec[j]--; // Decrease the count of that character
            }
        }
        return result; // Return the resulting string
    }
};
/*
Time Complexity->O(N)
Space Complexity->O(26)
*/
