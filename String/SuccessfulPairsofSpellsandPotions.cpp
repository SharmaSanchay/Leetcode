//Leetcode->2330(https://leetcode.com/problems/successful-pairs-of-spells-and-potions/description/)
class Solution {
public:
    // Helper function to count the number of valid pairs for a given spell and success threshold
    int checkforpairs(std::vector<int>& potions, int val, long long success) {
        int pairs = 0;  // This will store the number of valid pairs
        int s = 0, e = potions.size() - 1;  // Start and end indices for binary search

        // Binary search loop to find the point where potions[mid] * val >= success
        while (s <= e) {
            int mid = (s + e) / 2;  // Find the middle index of the current range
            long long checker = static_cast<long long>(potions[mid]) * val;  // Check the product of potions[mid] and val
            
            if (checker >= success) {
                // If potions[mid] * val >= success, all elements from mid to the end are valid
                pairs = potions.size() - mid;  // All potions from mid to the end will satisfy the condition
                e = mid - 1;  // Now, look in the left half for potentially smaller valid values
            } else {
                s = mid + 1;  // If the product is less than success, we need to try the larger values in the right half
            }
        }

        return pairs;  // Return the number of valid pairs for this specific spell
    }

    // Main function to calculate the number of successful pairs for all spells
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());  // Sort the potions array in ascending order

        vector<int> ans(spells.size(), 0);  // Initialize the result array with zeroes

        // Iterate over each spell in the spells array
        for (int i = 0; i < spells.size(); i++) {
            // For each spell, calculate the number of successful pairs by calling checkforpairs
            ans[i] = checkforpairs(potions, spells[i], success);
        }

        return ans;  // Return the result array containing the count of successful pairs for each spell
    }
};
/*
Time Complexity->O(NlogN)
Space Complexity->O(1)
*/
