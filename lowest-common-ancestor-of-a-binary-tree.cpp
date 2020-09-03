/* Problem url: https://leetcode.com/problems/arranging-coins/
 * Code by: ldcduc
 * */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> *list1;
    vector<TreeNode*> *list2;
    void visit(TreeNode* node, TreeNode* target, vector<TreeNode*> *list) {
        if (!list->empty() && list->back()->val == target->val) {
            return;
        }
        if (node) {
            list->push_back(node);
            visit(node->left, target, list);
            visit(node->right, target, list);
            if (list->back()->val != target->val) {
                list->pop_back();
            }
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* result;
        list1 = new vector<TreeNode*>;
        list2 = new vector<TreeNode*>;
        visit(root, p, list1);
        visit(root, q, list2);
        int i = 0;
        while (i < list1->size() && i < list2->size() && (*list1)[i] == (*list2)[i]) {
            result = (*list1)[i];
            ++i;
        }
        delete list1;
        delete list2;
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: binary tree
 * 
 * */

