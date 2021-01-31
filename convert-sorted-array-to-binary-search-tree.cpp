/* Problem url: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree
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
    TreeNode* recursion(vector<int>& nums, int l, int r) {
        if (l <= r) {
            int m = (l + r) >> 1;
            TreeNode* node = new TreeNode(nums[m]);
            node->left = recursion(nums, l, m - 1);
            node->right = recursion(nums, m + 1, r);
            return node;
        } 
        return NULL;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return recursion(nums, 0, nums.size() - 1);    
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: binary tree
 * 
 * */
