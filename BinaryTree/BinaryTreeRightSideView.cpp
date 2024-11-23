//Leetcode -> 199 (https://leetcode.com/problems/binary-tree-right-side-view/description/)
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
         if(root==nullptr){
        return {};
    }
    // simple level order traversal
   queue<TreeNode*>q;
   vector<int>ans;
   q.push(root);
   while(!q.empty()){
       int n = q.size();
       while(n){
               TreeNode *temp = q.front();
                q.pop();
                // last element present the current queue will be the right element of the binary tree
                if(n == 1){
                       ans.push_back(temp->val);
                }
               if(temp->left!=nullptr){
                   q.push(temp->left);
               }
               if(temp->right!=nullptr){
                   q.push(temp->right);
               }
               n--;
           }
   }
   return ans;
    }
};
/*
Time Complexity->O(N)
Space Complexity->O(N)
*/
