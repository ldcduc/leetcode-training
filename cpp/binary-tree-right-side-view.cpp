/* Problem url: https://leetcode.com/problems/binary-tree-right-side-view
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
    vector<int> result;
    
    void recursion(TreeNode* node, int level) {
        if (node) {
            if (result.size() < level + 1) {
                result.push_back(node->val);
            } else {
                result[level] = node->val;
            }
            recursion(node->left, level + 1);
            recursion(node->right, level + 1);
        }        
    }
    
    vector<int> rightSideView(TreeNode* root) {
        recursion(root, 0);
        return result;        
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: binary tree
 * 
 * */
