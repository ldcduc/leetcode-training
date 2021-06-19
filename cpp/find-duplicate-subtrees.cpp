/* Problem url: https://leetcode.com/problems/find-duplicate-subtrees
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
    unordered_map<string, vector<TreeNode*> > M;

    string dfs(TreeNode* node) {
        string res = "";
        if (node) {
            res = '(' + dfs(node->left) + to_string(node->val)  + dfs(node->right) + ')';
            M[res].push_back(node);
        }
        return res;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> result;
        dfs(root);
        for (auto it : M) {
            if (it.second.size() > 1) {
                result.push_back(it.second[0]);
            }
        }
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: binary search tree, trick, hash map
 * 
 * */

