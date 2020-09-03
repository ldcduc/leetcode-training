/* Problem url: https://leetcode.com/problems/maximum-binary-tree
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
    vector<int>* nums;

    void visit(TreeNode* &node, int l, int r) {
        int mid = l;
        for (int i = l + 1; i <= r; ++ i) {
            if ((*nums)[i] > (*nums)[mid]) {
                mid = i;
            }
        }
        node->val = (*nums)[mid];
        if (l <= mid - 1) {
            node->left = new TreeNode();
            visit(node->left, l, mid - 1);
        }
        if (mid + 1 <= r) {
            node->right = new TreeNode();
            visit(node->right, mid + 1, r);
        }
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty()) {
            return NULL;
        }
        this->nums = &nums;
        TreeNode* root = new TreeNode();
        visit(root, 0, nums.size() - 1);
        return root;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: binary tree
 * 
 * */

