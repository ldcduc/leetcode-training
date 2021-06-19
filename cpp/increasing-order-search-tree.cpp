/* Problem url: https://leetcode.com/problems/increasing-order-search-tree
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
    TreeNode* visit(TreeNode* node, TreeNode* res) {
        if (node) {
            res = visit(node->left, res);
            res->right = new TreeNode(node->val);
            res = res->right;
            res = visit(node->right, res);
        }
        return res;
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* tmp = new TreeNode();
        TreeNode* res = tmp;
        visit(root, tmp);
        res = res->right;
        delete tmp;
        return res;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: binary search tree, trick
 * 
 * */

