/* Problem url: https://leetcode.com/problems/maximum-difference-between-node-and-ancestor
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
    int visit(TreeNode* root, int maxVal, int minVal) {
        int result = 0;
        result = max(result, abs(maxVal - root->val));
        result = max(result, abs(minVal - root->val));
        if (root->left) {
            result = max(result, visit(root->left, max(maxVal, root->val), min(minVal, root->val)));
        }
        if (root->right) {
            result = max(result, visit(root->right, max(maxVal, root->val), min(minVal, root->val)));
        }
        return result;
    }
    int maxAncestorDiff(TreeNode* root) {
        return visit(root, root->val, root->val);
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: binary search tree
 * 
 * */

