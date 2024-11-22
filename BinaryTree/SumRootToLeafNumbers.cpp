//leetcode->129 (https://leetcode.com/problems/sum-root-to-leaf-numbers/description/)
class Solution {
public:
    void solve(TreeNode *root,int&Sum,int TempSum){
        if(!root) return;
        //making the number
        TempSum=TempSum*10+root->val;
        // check of the leaf node 
        if(root->left == nullptr && root->right == nullptr){
            Sum+=TempSum;
            return;
        }
        // going the left direction of the tree
        solve(root->left,Sum,TempSum);
        // going the right direction of the tree
        solve(root->right,Sum,TempSum);
    }
    int sumNumbers(TreeNode* root) {
        int Sum=0;
        solve(root,Sum,0);
        return Sum;
    }
};
/*
Time Complexity->O(N)
Space Complexity->O(N)
*/
