/* Problem url: https://leetcode.com/problems/binary-tree-inorder-traversal
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> stack_;
        if (root) {
            TreeNode* node;
            stack_.push(root);
            while (!stack_.empty()) {
                node = stack_.top();
                while (node->left != NULL) {
                    stack_.push(node->left);
                    node->left = NULL;
                    node = stack_.top();
                }

                node = stack_.top();
                result.push_back(node->val);
                stack_.pop();

                if (node->right != NULL) {
                    stack_.push(node->right);
                }
            }
        }
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: binary search tree, iteratively, in-order
 * 
 * */
