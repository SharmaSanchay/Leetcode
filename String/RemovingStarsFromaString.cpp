//Leetcode -> 2390 (https://leetcode.com/problems/removing-stars-from-a-string/)
class Solution {
public:
    string removeStars(string str) {
        string ans = "";
        for (int i = 0; i < str.length(); i++) {
            // check if the curr  element is * and string(ans) is non empty then pop out the last character
            if (!ans.empty() && str[i] == '*') {
                ans.pop_back();
            } else {
                ans += str[i];
            }
        }
        return ans;
    }
};
/*
Time Complexity->O(N)
Space Complexity->O(N)
*/
