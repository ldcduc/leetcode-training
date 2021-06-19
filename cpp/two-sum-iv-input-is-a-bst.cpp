/* Problem url: https://leetcode.com/problems/two-sum-iv-input-is-a-bst
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
    TreeNode* root;
    
    bool search(TreeNode* node, TreeNode* except, int val) {
        if (node) {
            if (val < node->val) {
                return search(node->left, except, val);
            } else if (val > node->val) {
                return search(node->right, except, val);
            } else {
                if (node != except) {
                    return true;
                } else {
                    return search(node->left, except, val) || search(node->right, except, val);
                }
            }
        }    
        return false;
    }
    bool visit(TreeNode* node, int k) {
        if (node) {
            return search(root, node, k - node->val) || visit(node->left, k) || visit(node->right, k);
        }
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        this->root = root;
        return visit(root, k);
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: binary search tree
 * 
 * */
