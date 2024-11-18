// Leetcode -> 205 (https://leetcode.com/problems/isomorphic-strings/)
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        // Create a map to store the mapping of characters from string s to string t
        map<char, char> m;

        // Initialize an empty string to build the transformed version of s
        string ans = "";

        // Map the first character of s to the first character of t
        m[s[0]] = t[0];
        ans += m[s[0]];

        // Iterate through the rest of the characters in string s
        for (int i = 1; i < s.length(); i++)
        {
            // Check if the current character of s is already mapped to a character in t
            if (m[s[i]])
            {
                // If mapped, add the corresponding character from t to ans
                ans += m[s[i]];
            }
            else
            {
                // If not mapped, check if the current character in t is already used
                for (auto v : m)
                {
                    // If already used, the strings are not isomorphic
                    if (v.second == t[i])
                    {
                        return false;
                    }
                }
                // Map the current character of s to the current character of t
                m[s[i]] = t[i];
                ans += m[s[i]];
            }
        }
        // Compare the transformed string ans with t to check if they are the same
        return ans == t ? true : false;
    }
};


//  You can think of something using map and set together
//  first we do mapping and in set we used to collect the used element of the t[i]
// if we get found a  element in set the current is used then we simply return false;
// Approach->2
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        map<char, char> m;
        unordered_set<char> used_chars;
        string ans = "";

        for (size_t i = 0; i < s.length(); ++i)
        {
            if (m.find(s[i]) != m.end())
            {
                ans += m[s[i]];
            }
            else
            {
                if (used_chars.find(t[i]) != used_chars.end())
                {
                    return false; // `t[i]` is already mapped to another character
                }
                m[s[i]] = t[i];
                used_chars.insert(t[i]);
                ans += m[s[i]];
            }
        }
        return ans == t ? true : false;
    }
};