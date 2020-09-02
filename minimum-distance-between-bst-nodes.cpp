/* Problem url: https://leetcode.com/problems/minimum-distance-between-bst-nodes
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
    stack<int> s;
    int visit(TreeNode* node) {
        int result = -1;
        if (node->left) {
            int t = visit(node->left);
            if (result == -1 || t < result) {
                result = t;
            }
        }

        if (!s.empty()) {
            if (result == -1 || node->val - s.top() < result) {
                result = node->val - s.top();
            }
            s.pop();
        }
        s.push(node->val);

        if (node->right) {
            int t = visit(node->right);
            if (result == -1 || t < result) {
                result = t;
            }
        }
        return result;
    }
    int minDiffInBST(TreeNode* root) {
        return visit(root);
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: binary search tree
 * 
 * */

