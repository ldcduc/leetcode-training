/* Problem url: https://leetcode.com/problems/flatten-binary-tree-to-linked-list
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
    void recursion(TreeNode* root, TreeNode*& result) {
        if (root) {
            TreeNode* left = root->left;
            TreeNode* right = root->right;
            root->left = NULL;
            root->right = NULL;
            if (result != NULL) {
                result->right = root;
            }
            result = root;
            recursion(left, result);
            recursion(right, result);
        }
    } 
    void flatten(TreeNode* root) {
        TreeNode* tmp = NULL;
        recursion(root, tmp);
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: binary tree
 * 
 * */
