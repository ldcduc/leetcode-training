/* Problem url: https://leetcode.com/problems/validate-binary-search-tree
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

    bool visit(TreeNode* node, bool hasMin, int minVal, bool hasMax, int maxVal) {
        if (node) {
            if ((hasMin && node->val <= minVal) || (hasMax && node->val >= maxVal)) {
                return false;
            }
            int checkLeft = visit(node->left, hasMin, minVal, true, hasMax ? min(maxVal, node->val) : node->val);
            int checkRight = visit(node->right, true, hasMin ? max(minVal, node->val) : node->val, hasMax, maxVal);
            return checkLeft && checkRight;
        }
        return true;
    }
    bool isValidBST(TreeNode* root) {
        if (root) {
            return visit(root, false, root->val, false, root->val);
        }
        return true;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: binary search tree
 * 
 * */
