//Leetcode->124 (https://leetcode.com/problems/binary-tree-maximum-path-sum/description/)
class Solution {
public:
    // Variable to store the maximum path sum
    int sub = INT_MIN;
    
    // Helper function to calculate the maximum path sum
    int solve(TreeNode *root) {
        // Base case: If the node is null, return 0
        if (!root) {
            return 0;
        }
        
        // Recursively calculate the maximum path sum for the left and right subtrees
        int ans1 = solve(root->left);
        int ans2 = solve(root->right);
        
        // Calculate the maximum path sum passing through the current node
        int pathsum = max(ans1, ans2) + root->val;
        // Case where only the current node is considered
        int only_root_good = root->val;
        // Case where both left and right subtrees are included along with the current node
        int include_both = ans1 + ans2 + root->val;
        
        // Update the global maximum path sum with the best possible value at the current node
        sub = max({only_root_good, include_both, pathsum, sub});
        
        // Return the maximum path sum for the current node considering it as an endpoint
        return max(only_root_good, pathsum);
    }
    
    // Function to find the maximum path sum in a binary tree
    int maxPathSum(TreeNode* root) {
        solve(root);
        return sub;
    }
};
/*
Time Complexity->O(N)
Space Complexity->O(N)
