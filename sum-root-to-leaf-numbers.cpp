/* Problem url: https://leetcode.com/problems/sum-root-to-leaf-numbers
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
    int recursion(TreeNode* node, int sum) {
        if (node) {
            sum = sum * 10 + node->val;
            if (node->left == NULL && node->right == NULL) {
                return sum;
            }   
            return recursion(node->left, sum) + recursion(node->right, sum);
        } 
        return 0;
    }
    int sumNumbers(TreeNode* root) {
        return recursion(root, 0);
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: binary tree
 * 
 * */
