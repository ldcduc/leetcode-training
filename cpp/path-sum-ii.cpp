/* Problem url: https://leetcode.com/problems/path-sum-ii/
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
    vector<int> path;

    void visit(TreeNode* node, int sum) {
        if (node != NULL) {
            path.push_back(node->val);
            if (node->left == NULL && node->right == NULL && sum - node->val == 0) {
                result.push_back(path);
            } else {
                visit(node->left, sum - node->val);
                visit(node->right, sum - node->val);
            }
            path.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        visit(root, sum);
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: binary search tree
 * 
 * */

