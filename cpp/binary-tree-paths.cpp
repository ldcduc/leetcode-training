/* Problem url: https://leetcode.com/problems/binary-tree-paths
 * Code by: ldcduc
 * */
/* Begin of Solution */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void recursion(vector<string> &result, string path, TreeNode* node) {
        if (node) {
            path += (path.empty() ? "" : "->") + to_string(node->val);
            if (node->left || node->right) {
                recursion(result, path, node->left);
                recursion(result, path, node->right);
            } else {
                if (!path.empty()) {
                    result.push_back(path);
                }
            }
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        recursion(result, "", root); 
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: binary tree
 * 
 * */
