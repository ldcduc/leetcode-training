/* Problem url: https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers
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
    int visit(TreeNode* root, int sum) {
        if (root) {
            sum = sum << 1 | root->val;
            if (!root->left && !root->right) {
                return sum;
            }
            return visit(root->left, sum) + visit(root->right, sum);
        }
        return 0;
    }
    int sumRootToLeaf(TreeNode* root) {
        return visit(root, 0);
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: binary tree, tree traversal
 * 
 * */
