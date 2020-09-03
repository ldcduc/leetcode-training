/* Problem url: https://leetcode.com/problems/insert-into-a-binary-search-tree
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root) {
            if (val < root->val) {
                root->left = insertIntoBST(root->left, val);
            } else {
                root->right = insertIntoBST(root->right, val);
            }
            return root;
        }
        root = new TreeNode(val);
        return root;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: binary search tree
 * 
 * */

