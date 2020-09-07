/* Problem url: https://leetcode.com/problems/serialize-and-deserialize-bst
 * Code by: ldcduc
 * */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root) {
            return '(' + to_string(root->val) + serialize(root->left) + serialize(root->right) + ')';
        }
        return "()";
    }

    // Decodes your encoded data to tree.
    TreeNode* decode(string data, int &index) {
        TreeNode* node = NULL;
        if (data[++index] != ')') {
            int val = 0;
            while ('0' <= data[index] && data[index] <= '9') {
                val = val * 10 + data[index] - '0';
                ++index;
            }
            cout << val << endl;
            node = new TreeNode(val);
            node->left = decode(data, index);
            node->right = decode(data, index);
        }
        ++index;
        return node;
    }
    TreeNode* deserialize(string data) {
        cout << data << endl;
        int index = 0;
        return decode(data, index);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
/*
 * Comment by ldcduc
 * Suggested tags: binary search tree, serialize, deserialize
 * 
 * */

