/* Problem url: https://leetcode.com/problems/second-minimum-node-in-a-binary-tree
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
    int result;
    int rootVal;

    void visit(TreeNode* node) {
        if (node) {
            if (node->val > rootVal && (result == -1 || node->val < result)) {
                result = node->val;
            }
            visit(node->left);
            visit(node->right);
        }
    }
    int findSecondMinimumValue(TreeNode* root) {
        if (root) {
            result = -1;
            rootVal = root->val;
            visit(root);
            return result;
        }
        return -1;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: 
 * 
 * */

