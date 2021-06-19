/* Problem url: https://leetcode.com/problems/average-of-levels-in-binary-tree
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
    vector<pair<double, int>> sums;

    void visit(TreeNode* node, int level) {
        if (node) {
            if (sums.size() <= level) {
                sums.push_back(make_pair(node->val, 1));
            } else {
                sums[level].first += node->val;
                ++sums[level].second;
            }
            visit(node->left, level + 1);
            visit(node->right, level + 1);
        }
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        visit(root, 0);
        for (auto item : sums) {
            result.push_back(item.first / item.second);
        }
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: binary search tree
 * 
 * */

