//Leetcode->238(https://leetcode.com/problems/product-of-array-except-self/description/)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // Initialize prefix and suffix arrays of the same size as arr
        vector<int> prefix(arr.size());
        vector<int> suffix(arr.size());

        // Compute prefix products
        for (int i = 0; i < arr.size(); i++) {
            if (i != 0) {
                // Each prefix element is the product of the previous prefix element and the current arr element
                prefix[i] = prefix[i - 1] * arr[i];
            } else {
                // First element of prefix is the same as the first element of arr
                prefix[i] = arr[i];
            }
        }

        // Compute suffix products and update the arr to store the result
        for (int i = arr.size() - 1; i >= 0; i--) {
            if (i == arr.size() - 1) {
                // Last element of suffix is the same as the last element of arr
                suffix[i] = arr[i];
                // Update arr's last element with the prefix product of the second last element
                arr[i] = prefix[i - 1];
            } else if (i == 0) {
                // Update arr's first element with the suffix product of the second element
                arr[i] = suffix[i + 1];
            } else {
                // Each suffix element is the product of the next suffix element and the current arr element
                suffix[i] = suffix[i + 1] * arr[i];
                // Update arr with the product of prefix of the previous element and suffix of the next element
                arr[i] = prefix[i - 1] * suffix[i + 1];
            }
        }
        // Return the updated arr
        return arr;
    }
};
/*
Time Complexity->O(N)
Space Complexity->O(N)
*/
