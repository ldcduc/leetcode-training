/* Problem url: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree
 * Code by: ldcduc
 * */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* node;
        vector<TreeNode*> list1;
        vector<TreeNode*> list2;
        node = root;
        while (true) {
            list1.push_back(node);
            if (node == p) {
                break;
            } else if (p->val < node->val) {
                node = node->left;
            } else {
                node = node->right;
            }
        }
        node = root;
        while (true) {
            list2.push_back(node);
            if (node == q) {
                break;
            } else if (q->val < node->val) {
                node = node->left;
            } else {
                node = node->right;
            }
        }
        int i = 0;
        TreeNode* result;
        while (i < list1.size() && i < list2.size() && list1[i] == list2[i]) {
            result = list1[i];
            ++i;
        }
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: binary search tree
 * 
 * */

