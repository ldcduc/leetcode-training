/* Problem url: https://leetcode.com/problems/binary-tree-postorder-traversal
 * Code by: ldcduc
 * */
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        if (root) {
            s.push(root);
            while (!s.empty()) {
                root = s.top();
                if (root->left) {
                    s.push(root->left);
                    root->left = NULL;
                } else if (root->right) {
                    s.push(root->right);
                    root->right = NULL;
                } else {
                    result.push_back(root->val);
                    s.pop();
                }
            }
        }
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: binary search tree, iteratively, post-order
 * 
 * */

