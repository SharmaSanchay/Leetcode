//Leetcode -> 117 (https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/)
class Solution {
public:
    Node* connect(Node* root) {
        Node *curr = root; // Pointer to keep track of the current node at the current level

        while (root != nullptr) {
            Node *tempchild = new Node(0); // Temporary dummy node to build the next level's connections
            Node *CurrChild = tempchild;   // Pointer to connect the children nodes

            while (root != nullptr) {
                if (root->left != nullptr) {
                    CurrChild->next = root->left; // Connect the left child
                    CurrChild = CurrChild->next;  // Move the pointer to the next position
                }

                if (root->right != nullptr) {
                    CurrChild->next = root->right; // Connect the right child
                    CurrChild = CurrChild->next;   // Move the pointer to the next position
                }

                root = root->next; // Move to the next node at the current level
            }

            root = tempchild->next; // Move to the next level
        }

        return curr; // Return the root of the modified tree
    }
};
/*
Time Complexity->O(N)
Space Complexity->O(1)
