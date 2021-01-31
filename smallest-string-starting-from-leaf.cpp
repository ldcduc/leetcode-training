/* Problem url: https://leetcode.com/problems/smallest-string-starting-from-leaf
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
    void minimize(string &result, string s) {
        int len = min(result.length(), s.length());
        for (int i = 0; i < len; ++ i) {
            if (s[i] < result[i]) {
                result = s;
            } else if (s[i] > result[i]) {
                return;
            }
        }
        if (s.length() < result.length()) {
            result = s;
        }
    }
    void recursion(TreeNode* node, string s, string &result) {
        if (node) {
            s = char('a' + node->val) + s;
            recursion(node->left, s, result);
            recursion(node->right, s, result);
            if (node->left == NULL && node->right == NULL) {
                if (result.empty()) {
                    result = s;
                } else {
                    minimize(result, s);
                }    
            }
        } 
    }
    string smallestFromLeaf(TreeNode* root) {
        string result = "";
        recursion(root, "", result);    
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: binary tree, string
 * 
 * */
