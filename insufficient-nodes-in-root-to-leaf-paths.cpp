/* Problem url: https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths
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
    int limit;
    bool visit(TreeNode* node, int sum) {
        if (node) {
            sum += node->val;
            if (node->left == NULL && node->right == NULL) {
                return (sum < this->limit);
            }
            int leftResult = visit(node->left, sum);
            int rightResult = visit(node->right, sum);
            if (leftResult) {
                delete node->left;
                node->left = NULL;
            }
            if (rightResult) {
                delete node->right;
                node->right = NULL;
            }
            return leftResult && rightResult;
        }
        return true;
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        this->limit = limit;
        if (visit(root, 0)) {
            root = NULL;
        };
        return root;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: binary search tree
 * 
 * */

