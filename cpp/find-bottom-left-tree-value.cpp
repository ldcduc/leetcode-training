/* Problem url: https://leetcode.com/problems/find-bottom-left-tree-value
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
    int level = -1, result;
    void visit(TreeNode* node, int level) {
        if (node) {
            visit(node->left, level + 1);
            visit(node->right, level + 1);
            if (level > this->level) {
                result = node->val;
                this->level = level;
            }
        }
    }
    int findBottomLeftValue(TreeNode* root) {
        visit(root, 0);
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: binary search tree
 * 
 * */

