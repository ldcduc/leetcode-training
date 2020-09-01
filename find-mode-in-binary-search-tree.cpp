/* Problem url: https://leetcode.com/problems/find-mode-in-binary-search-tree
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
    unordered_map<int, int> map_;
    int mostFrequency;

    void visit(TreeNode* node) {
        if (node) {
            ++map_[node->val];
            if (map_[node->val] > mostFrequency) {
                mostFrequency = map_[node->val];
            }
            visit(node->left);
            visit(node->right);
        }
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        visit(root);
        for (auto element : map_) {
            if (element.second == mostFrequency) {
                result.push_back(element.first);
            }
        }
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: binary search tree
 * 
 * */

