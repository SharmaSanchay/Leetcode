// Leetcode 297 (https://leetcode.com/problems/serialize-and-deserialize-binary-tree/)
class Codec 
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        // using the type cast techniqe for both Serialize and DeSerialize
        unsigned long long number = (unsigned long long)root;
        return to_string(number);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        unsigned long long number = stoull(data);
        return (TreeNode *)number;
    }
};
/*
Time Complexity -> O(1)
Space Complexity -> O(1)
*/
