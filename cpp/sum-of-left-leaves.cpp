/* Problem url: https://leetcode.com/problems/sum-of-left-leaves
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
    int recursion(TreeNode* node) {
        if (node) {
            int result = 0;
            if (node->left && (node->left->left == NULL && node->left->right == NULL)) {
                result += node->left->val;    
            }
            result += recursion(node->left);
            result += recursion(node->right);
            return result;
        }    
        return 0;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return recursion(root); 
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: binary tree
 * 
 * */
