/* Problem url: https://leetcode.com/problems/symmetric-tree
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
class RecursiveSolution {
public:
    bool recursion(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL || root2 == NULL) {
            return root1 == NULL && root2 == NULL;
        }
        return root1->val == root2->val && recursion(root1->left, root2->right) && recursion(root1->right, root2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (root) {
            return recursion(root->left, root->right);    
        }    
        return true;
    }
};
class IterativeSolution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<pair<TreeNode*, TreeNode*>> Q;
        if (root) {
            Q.push(make_pair(root->left, root->right));
            while (!Q.empty()) {
                TreeNode* root1 = Q.front().first, * root2 = Q.front().second;
                Q.pop();
                if (root1 && root2) {
                    if (root1->val != root2->val) {
                        return false;
                    }
                    Q.push(make_pair(root1->left, root2->right));
                    Q.push(make_pair(root1->right, root2->left));
                }
                if ((root1 == NULL) ^ (root2 == NULL)) {
                    return false;
                }
            }
        }    
        return true;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: recursion
 * 
 * */
