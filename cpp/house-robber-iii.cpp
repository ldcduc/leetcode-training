/* Problem url: https://leetcode.com/problems/house-robber-iii
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
class DPNode : public TreeNode {
public:
    int val;
    vector<int> dpChildren;
    DPNode* left, * right;
    DPNode() {
        val = 0;
    }
};

class Solution {
public:
    int visit(DPNode* dpNode, TreeNode* node) {
        if (node) {
            int maxDpDescendant = 0;
            int maxDpChildren = 0;
            if (node->left) {
                dpNode->left = new DPNode();
                maxDpChildren += visit(dpNode->left, node->left);
                for (auto item : dpNode->left->dpChildren) {
                    maxDpDescendant += item;
                }
                dpNode->dpChildren.push_back(dpNode->left->val);
            }
            if (node->right) {
                dpNode->right = new DPNode();
                maxDpChildren += visit(dpNode->right, node->right);
                for (auto item : dpNode->right->dpChildren) {
                    maxDpDescendant += item;
                }
                dpNode->dpChildren.push_back(dpNode->right->val);
            }
            dpNode->val = max(maxDpChildren, maxDpDescendant + node->val);
            return dpNode->val;
        }
        return 0;
    }
    int rob(TreeNode* root) {
        DPNode* dpRoot = new DPNode();
        return visit(dpRoot, root);
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: binary search tree, dynamic programming on tree
 * 
 * */

