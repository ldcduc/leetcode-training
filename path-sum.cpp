/* Problem url: https://leetcode.com/problems/path-sum/
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
    bool visit(TreeNode* node, int sum) {
        if (node == NULL) {
            return false;
        }
        if (node->left == NULL && node->right == NULL) {
            return (sum - node->val == 0);
        } 
        return (node->left == NULL ? false : visit(node->left, sum - node->val)) \
                || \
               (node->right == NULL ? false : visit(node->right, sum - node->val));
    }
    bool hasPathSum(TreeNode* root, int sum) {
        return visit(root, sum);     
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: binary search tree
 * 
 * */

