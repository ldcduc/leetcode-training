/* Problem url: https://leetcode.com/problems/binary-tree-inorder-traversal
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
    
    void visit(TreeNode* root) {
        if (root != NULL) {
            visit(root->left);
            result.push_back(root->val);
            visit(root->right);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        visit(root); 
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: math, careful
 * 
 * */
