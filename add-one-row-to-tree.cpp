/* Problem url: https://leetcode.com/problems/add-one-row-to-tree
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
    void visit(TreeNode* root, int level, int v, int d) {
        if (root) {
            if (level + 1 == d) {
                TreeNode* node = new TreeNode(v);
                node->left = root->left;
                root->left = node;
                node = new TreeNode(v);
                node->right = root->right;
                root->right = node;
            } else {
                visit(root->left, level + 1, v, d);
                visit(root->right, level + 1, v, d);
            }
        }
    }
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode* node = new TreeNode(v);
            node->left = root;
            root = node;
        } else {
            visit(root, 1, v, d);
        }
        return root;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: binary search tree
 * 
 * */

