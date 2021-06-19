/* Problem url: https://leetcode.com/problems/convert-bst-to-greater-tree
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
    void recursion(vector<TreeNode*> &arr, TreeNode* root, int flag) {
        if (root) {
            arr.push_back(root); 
            recursion(arr, root->left, flag);
            recursion(arr, root->right, flag);
        }
    }
    TreeNode* convertBST(TreeNode* root) {
        vector<TreeNode*> arr;
        recursion(arr, root, 0);
        sort(arr.begin(), arr.end(), [](TreeNode* x, TreeNode* y) {
            return x->val > y->val; 
        });
        int tmp = 0;
        for (int i = 0; i < arr.size(); ++ i) {
            arr[i]->val += tmp;
            tmp = arr[i]->val;
        }
        return root;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: binary tree, fun
 * 
 * */
