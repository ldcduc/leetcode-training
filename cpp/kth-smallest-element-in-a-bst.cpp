/* Problem url: https://leetcode.com/problems/kth-smallest-element-in-a-bst
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
    int result;

    int countSubtree(TreeNode* node, int k, int cntLess) {
        if (node) {
            int cntLeft = countSubtree(node->left, k, cntLess);
            if (cntLess + cntLeft == k - 1) {
                this->result = node->val;
            }
            int cntRight = countSubtree(node->right, k, cntLess + cntLeft + 1);
            return cntLeft + cntRight + 1;
        }
        return 0;
    }
    int kthSmallest(TreeNode* root, int k) {
        countSubtree(root, k, 0);
        return this->result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: binary search tree, kth smallest
 * 
 * */

