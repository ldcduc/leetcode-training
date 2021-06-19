/* 
 * Problem url: https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/
 * Code by ldcduc
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
    TreeNode* recoverFromPreorder(string S) {
        vector<pair<int, int> > node;
        int first_value = 0, i=0;
        while (i < S.length() && S[i] != '-') 
            first_value = first_value * 10 + S[i] - '0', ++i;
        node.push_back(make_pair(first_value, 0));
        for (; i<S.length(); ) {
            int level = 0;
            while (i < S.length() && S[i] == '-')
                ++level, ++i;
            int value = 0;
            while (i < S.length() && S[i] != '-')
                value = value * 10 + S[i] - '0', ++i;
            node.push_back(make_pair(value, level));
        }
        TreeNode *root = NULL;
        stack<pair<int, TreeNode*> > s;
        for (auto i:node) {
            while (!s.empty() && s.top().first != i.second-1) {
                s.pop(); 
            }
            TreeNode *node = new TreeNode(i.first);
            if (s.empty()) {
                root = node;
            } else {
                TreeNode *parent = s.top().second; 
                if (parent->left == NULL) {
                    parent->left = node; 
                } else {
                    parent->right = node;
                }
            }
            s.push(make_pair(i.second, node));
        }
        return root;
    }
};

/* 
 * Comment by ldcduc
 *
 * */
