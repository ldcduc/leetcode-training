/* Problem url: https://leetcode.com/problems/range-sum-of-bst
 * Code by: ldcduc
 * */
/* Begin of Solution */
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
    int rangeSumBST(TreeNode* root, int L, int R) {
        return root ? rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R) + (L <= root->val && root->val <= R) * root->val : 0;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: binary search tree
 * 
 * */
