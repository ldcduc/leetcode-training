/* Problem url: https://leetcode.com/problems/binary-tree-postorder-traversal
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
            visit(result, root->left);
            visit(result, root->right);
            result.push_back(root->val);
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        visit(result, root);
        return result;
    }
};
class IterativeSolution {
/* This solution does not modify the tree structure */
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root) {
            stack<TreeNode*> S;
            TreeNode* cur = root;
            do {
                while (cur) {
                    if (cur->right) {
                        S.push(cur->right);
                    }
                    S.push(cur);
                    cur = cur->left;
                }
                cur = S.top();
                S.pop();
                if (cur->right && !S.empty() && S.top() == cur->right) {
                    S.pop();
                    S.push(cur);
                    cur = cur->right;
                } else {
                    result.push_back(cur->val);
                    cur = NULL;
                }
            } while (!S.empty());
        }
        return result;
    }
};
class IterativeSolution {
/* This solution modifies the tree structure */
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        if (root) {
            s.push(root);
            while (!s.empty()) {
                root = s.top();
                if (root->left) {
                    s.push(root->left);
                    root->left = NULL;
                } else if (root->right) {
                    s.push(root->right);
                    root->right = NULL;
                } else {
                    result.push_back(root->val);
                    s.pop();
                }
            }
        }
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: binary search tree, iteratively, post-order
 * 
 * */

