//Leetcode -> 515 (https://leetcode.com/problems/find-largest-value-in-each-tree-row/)
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        // If the root is null, return an empty vector
        if (root == NULL) return {};

        // Initialize a queue to perform a level-order traversal
        queue<TreeNode*> que;
        que.push(root);

        // Vector to store the largest values in each row
        vector<int> ans;

        // Perform the level-order traversal
        while (!que.empty()) {
            int n = que.size(); // Number of nodes in the current level
            int largestrow = INT_MIN; // Initialize the largest value for the current row to the minimum integer value

            // Iterate through all nodes in the current level
            while (n--) {
                TreeNode* temp = que.front(); // Get the front node in the queue
                que.pop(); // Remove the front node from the queue
                largestrow = max(largestrow, temp->val); // Update the largest value for the current row

                // If the left child exists, add it to the queue
                if (temp->left != nullptr) {
                    que.push(temp->left);
                }

                // If the right child exists, add it to the queue
                if (temp->right != nullptr) {
                    que.push(temp->right);
                }
            }

            // Add the largest value of the current row to the answer vector
            ans.push_back(largestrow);
        }

        // Return the result vector containing the largest values in each row
        return ans;
    }
};
/*
Time Complexity->O(N)
Space Complexity->O(N)
*/
