/* Problem url: https://leetcode.com/problems/binary-tree-inorder-traversal
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
class RecursiveSolution {
public:
    void visit(vector<int> &result, TreeNode* root) {
        if (root) {
            visit(result, root->left);
            result.push_back(root->val);
            visit(result, root->right);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        visit(result, root);
        return result;
    }
};
class IterativeSolution { // This solution does not modify the tree
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> S;
        TreeNode* cur = root;
        while (cur || !S.empty()) {
            while (cur) {
                S.push(cur);
                cur = cur->left;
            }
            cur = S.top();
            S.pop();
            result.push_back(cur->val);
            cur = cur->right;
        }
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: binary search tree, iteratively, in-order
 * 
 * */
