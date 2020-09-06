/* Problem url: https://leetcode.com/problems/all-elements-in-two-binary-search-trees
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
    vector<int> result;
    void visit(TreeNode* node) {
        if (node) {
            result.push_back(node->val);
            visit(node->left);
            visit(node->right);
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        visit(root1);
        visit(root2);
        sort(result.begin(), result.end());
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: binary search tree, tree traversal, merging
 * 
 * */

