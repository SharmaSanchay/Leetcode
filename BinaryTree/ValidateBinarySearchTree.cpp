//Leetcode->98 (https://leetcode.com/problems/validate-binary-search-tree/)
class Solution {
public:
    bool isvalidbst(TreeNode *root,long minvalue,long maxvalue){
        if(root==nullptr){
            return true;
        } 
	// checking if the current node is in the range
        if(root->val >=maxvalue || root->val <=minvalue){return false;}
        return isvalidbst(root->left,minvalue,root->val) && isvalidbst(root->right,root->val,maxvalue);
    }
    bool isValidBST(TreeNode* root) {
        return isvalidbst(root,LLONG_MIN,LLONG_MAX);
    }
};
/*
Time Complexity->O(N)
Space Complexity->O(H)
*/
