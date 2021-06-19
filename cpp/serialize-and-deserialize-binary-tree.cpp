/* Problem url: https://leetcode.com/problems/serialize-and-deserialize-binary-tree
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
    void serialize(TreeNode* root, string& result) {
        if (root) {
            result += result.empty() ? to_string(root->val) : ',' + to_string(root->val);
            serialize(root->left, result);
            serialize(root->right, result);
        } else {
            result += result.empty() ? "null" : ",null";
        }
    }
    string serialize(TreeNode* root) {
        string result = "";
        if (root) {
            serialize(root, result);
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data, int& it) {
        string str = "";
        for (; data[it] != ','; ++ it) {
            str += data[it];
        }
        TreeNode* node = NULL;
        if (str != "null" && str != "") {
            node = new TreeNode(stoi(str));
            node->left = deserialize(data, ++ it);
            node->right = deserialize(data, ++ it);
        }
        return node;
    }
    TreeNode* deserialize(string data) {
        int index = 0;
        data += ',';
        return deserialize(data, index);
    }
};
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        if (root) {
            res = '(' + to_string(root->val) + serialize(root->left) + serialize(root->right) + ')';
        } else {
            res = "()";
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* decode(string data, int &index) {
        TreeNode* node = NULL;
        if (data[++index] != ')') {
            int val = 0;
            if (data[index] == '-') {
                val = -(data[++index] - '0');
                ++index;
            }
            while ('0' <= data[index] && data[index] <= '9') {
                val = val * 10 + data[index] - '0';
                ++index;
            }
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

