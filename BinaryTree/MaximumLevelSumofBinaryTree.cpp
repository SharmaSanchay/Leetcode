//Leetcode->1161(https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/)
class Solution {
public:
    int maxsum = INT_MIN; // Initialize maxsum to the smallest integer value
    int sum = 0;          // Initialize sum to store the sum of nodes at the current level
    int level;            // Initialize level to store the level with the maximum sum
    int dummylevel = 0;   // Initialize dummylevel to keep track of the current level

    // Helper function to perform level-order traversal and find the level with the maximum sum
    void helper(TreeNode *root) {
        queue<TreeNode*> q; // Initialize a queue for level-order traversal
        q.push(root);
        q.push(nullptr); // Use nullptr as a marker for the end of a level

        while (!q.empty()) {
            TreeNode *temp = q.front(); // Get the front node from the queue
            q.pop();

            // If nullptr is encountered, it means the end of the current level
            if (temp == nullptr) {
                // Check if the current level's sum is greater than the maxsum
                if (maxsum < sum) {
                    maxsum = sum;     // Update maxsum with the current level's sum
                    level = dummylevel; // Update the level with the current level
                    dummylevel++;       // Move to the next level
                    sum = 0;            // Reset the sum for the next level
                } else {
                    sum = 0;           // Reset the sum for the next level
                    dummylevel++;      // Move to the next level
                }
                // If the queue is not empty, push another nullptr to mark the end of the next level
                if (!q.empty()) {
                    q.push(nullptr);
                }
            } else {
                // Add the current node's value to the sum
                sum = sum + temp->val;
                // Push the left child to the queue if it exists
                if (temp->left != nullptr) {
                    q.push(temp->left);
                }
                // Push the right child to the queue if it exists
                if (temp->right != nullptr) {
                    q.push(temp->right);
                }
            }
        }
    }

    // Function to find the level with the maximum sum
    int maxLevelSum(TreeNode* root) {
        helper(root);  // Call the helper function to perform level-order traversal
        return level + 1; // Return the level with the maximum sum (1-based index)
    }
};
/*
Time Complexity->O(N)
Space Complexity->O(N)
*/