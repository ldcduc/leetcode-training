/* Problem url: https://leetcode.com/problems/balanced-binary-tree
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
    int recursion(TreeNode* root) { // return -1 if non-balanced
        if (root) {
            int lheight = recursion(root->left);
            int rheight = recursion(root->right);
            if (lheight < 0 || rheight < 0 || abs(lheight - rheight) > 1) {
                return -1;
            }
            return max(lheight, rheight) + 1;
        }    
        return 0;
    }
    bool isBalanced(TreeNode* root) {
        return (recursion(root) >= 0);    
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: 
 * 
 * */
