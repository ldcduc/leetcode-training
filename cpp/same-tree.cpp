/* Problem url: https://leetcode.com/problems/same-tree
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
    bool check(TreeNode* p, TreeNode* q) {
        if (p && q) {
            return p->val == q->val ? check(p->left, q->left) && check(p->right, q->right) : false;
        } else {
            return (p == NULL) == (q == NULL);
        }
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return check(p, q);    
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: recursion
 * 
 * */
