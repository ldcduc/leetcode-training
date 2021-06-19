/* Problem url: https://leetcode.com/problems/delete-node-in-a-bst
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
    TreeNode* findInorderSuccessor(TreeNode* node) {
        while (node->left != NULL) {
            node = node->left;
        }
        return node;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root) {
            if (key < root->val) {
                root->left = deleteNode(root->left, key);
            } else if (root->val < key) {
                root->right = deleteNode(root->right, key);
            } else {
                if (root->left == NULL) {
                    TreeNode* node = root->right;
                    delete root;
                    root = node;
                } else if (root->right == NULL) {
                    TreeNode* node = root->left;
                    delete root;
                    root = node;
                } else {
                    TreeNode* node = findInorderSuccessor(root->right); 
                    root->val = node->val;
                    root->right = deleteNode(root->right, root->val);
                }
            }
            return root;
        } 
        return NULL;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: binary search tree, delete node
 * 
 * */
