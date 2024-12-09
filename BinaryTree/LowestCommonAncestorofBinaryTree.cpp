//Leetcode-> 236 (https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/)
class Solution {
public:
    // Function to find the lowest common ancestor of two nodes p and q in a binary tree
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // If root is null, return null (base case for recursion)
        if (!root)
            return NULL;
        
        // If root matches either p or q, return root (LCA is found)
        if (root->val == p->val || root->val == q->val)
            return root;
        
        // Recursively search for LCA in the left subtree
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        // Recursively search for LCA in the right subtree
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        
        // If both left and right calls return non-null values,
        // it means p and q are found in different subtrees,
        // so root is their LCA.
        if (l && r)
            return root;
        
        // If only one of the calls returns a non-null value,
        // return that value (either left or right).
        return l ? l : r;
    }
};
/*
Time Complexity->O(N)
Space Complexity->O(N)
*/
