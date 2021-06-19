/* Problem url: https://leetcode.com/problems/binary-tree-preorder-traversal
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
class RecursiveSolution {
public:
    void visit(vector<int> &result, TreeNode* root) {
        if (root) {
            result.push_back(root->val);
            visit(result, root->left);
            visit(result, root->right);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        visit(result, root);
        return result;
    }
};
class IterativeSolution {
/* This solution does not modify the tree structure */
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root) {
            stack<TreeNode*> S;
            S.push(root);
            TreeNode* cur;
            while (!S.empty()) {
                cur = S.top();
                S.pop();
                result.push_back(cur->val);
                if (cur->right) {
                    S.push(cur->right);
                }
                if (cur->left) {
                    S.push(cur->left);
                }
            }
        }
        return result;
    }
};
class IterativeSolutionWhichModifiesTheTree {
/* This solution modifies the tree structure */
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        s.push(root);
        if (root) {
            result.push_back(root->val);
            while (!s.empty()) {
                root = s.top();
                if (root->left) {
                    result.push_back(root->left->val);
                    s.push(root->left);
                    root->left = NULL;
                } else {
                    s.pop();
                    if (root->right) {
                        result.push_back(root->right->val);
                        s.push(root->right);
                        root->right = NULL;
                    }
                }
            }
        }
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: binary search tree, iteratively, pre-order
 * 
 * */

