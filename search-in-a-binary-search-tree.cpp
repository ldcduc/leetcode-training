/* Problem url: https://leetcode.com/problems/search-in-a-binary-search-tree/
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL || root->val == val) {
            return (root ? root : NULL);
        }
        if (root->val > val) {
            return searchBST(root->left, val);
        }
        return searchBST(root->right, val);    
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: Binary search tree
 * Be aware of NULL pointer
 * */
