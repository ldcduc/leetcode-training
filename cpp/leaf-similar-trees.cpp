/* Problem url: https://leetcode.com/problems/leaf-similar-trees
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
    vector<int>* list1;
    vector<int>* list2;
    void visit(TreeNode* node, vector<int>* list) {
        if (node->left) {
            visit(node->left, list);
        }
        if (node->right) {
            visit(node->right, list);
        }
        if (node->left == NULL && node->right == NULL) {
            list->push_back(node->val);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        list1 = new vector<int>;
        list2 = new vector<int>;
        if (root1) {
            visit(root1, list1);
        }
        if (root2) {
            visit(root2, list2);
        }
        if (list1->size() != list2->size()) {
            delete list1;
            delete list2;
            return false;
        }
        for (vector<int>::iterator i1 = list1->begin(), i2 = list2->begin(); i1 != list1->end() && i2 != list2->end(); ++ i1, ++ i2) {
            if (*i1 != *i2) {
                cout << *i1 << ' ' << *i2 << endl;
                delete list1;
                delete list2;
                return false;
            }
        }
        delete list1;
        delete list2;
        return true;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: binary search tree
 * 
 * */

