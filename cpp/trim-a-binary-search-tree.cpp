/* Problem url: https://leetcode.com/problems/trim-a-binary-search-tree
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
    TreeNode* recursion(TreeNode* node, int low, int high) {
        if (node) {
            if (node->val > high) {
                return recursion(node->left, low, high);
            } else if (node->val < low) {
                return recursion(node->right, low, high);
            } else {
                node->left = recursion(node->left, low, high);
                node->right = recursion(node->right, low, high);
                return node;
            }    
        }
        return node;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return recursion(root, low, high);    
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: binary search tree
 * 
 * */
