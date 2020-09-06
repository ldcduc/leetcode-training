/* Problem url: https://leetcode.com/problems/construct-string-from-binary-tree
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
    string result;
    Solution() {
        result = "";
    }
    void visit(TreeNode* node) {
        if (node) {
            result += to_string(node->val);
            if (node->left) {
                result += '(';
                visit(node->left);
                result += ')';
                if (node->right) {
                    result += '(';
                    visit(node->right);
                    result += ')';
                }
            } else {
                if (node->right) {
                    result += "()";
                    result += '(';
                    visit(node->right);
                    result += ')';
                }
            }
        }
    }
    string tree2str(TreeNode* t) {
        visit(t);
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: binary search tree, string, implementation
 * 
 * */

