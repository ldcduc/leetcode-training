/* Problem url: https://leetcode.com/problems/minimum-depth-of-binary-tree
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
    int recursion(TreeNode* root) {
        if (root->left && root->right) {
            return min(recursion(root->left), recursion(root->right)) + 1;
        } else if (root->left) {
            return recursion(root->left) + 1;
        } else if (root->right) {
            return recursion(root->right) + 1;
        }
        return 1;
    }
    int minDepth(TreeNode* root) {
        return root ? recursion(root) : 0;    
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: binary tree
 * 
 * */
