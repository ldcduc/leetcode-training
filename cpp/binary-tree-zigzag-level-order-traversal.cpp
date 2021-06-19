/* Problem url: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal
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
    vector<vector<int>> result;

    void visit(TreeNode* node, int level) {
        if (node) {
            if (result.size() <= level) {
                result.push_back(vector<int>(1, node->val));
            } else {
                result[level].push_back(node->val);
            }
            visit(node->left, level + 1);
            visit(node->right, level + 1);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        visit(root, 0);
        for (int i = 0; i < result.size(); ++ i) {
            if (i % 2) {
                for (int j = 0; j < result[i].size() / 2; ++ j) {
                    swap(result[i][j], result[i][result[i].size() - j - 1]);
                }
            }
        }
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: binary search tree, tree traversal
 * 
 * */

