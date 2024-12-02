//Leetcode->49(https://leetcode.com/problems/group-anagrams/)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Create a map to store the sorted string as key and its anagrams as values
        unordered_map<string, vector<string>> mp;
        
        // Iterate over each string in the input vector
        for (auto x : strs) {
            // Copy the original string to a new variable 'word'
            string word = x;
            // Sort the characters of the string 'word'
            sort(word.begin(), word.end());
            // Use the sorted string 'word' as the key and push the original string 'x' into the map
            mp[word].push_back(x);
        }
        
        // Create a vector to store the grouped anagrams
        vector<vector<string>> ans;
        // Iterate over the map and push each group of anagrams into the answer vector
        for (auto x : mp) {
            ans.push_back(x.second);
        }
        // Return the grouped anagrams
        return ans;
    }
};
/*
Time Complexity->O(N.klogK)
Space Complexity->O(N.k)
*/
