/* Problem url: https://leetcode.com/problems/path-sum-ii/
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
    int result = 0;
    int givenSum;
    vector<int> sumsAlongThePath;

    void visit(TreeNode* node, int sum) {
        if (node != NULL) {
            sum += node->val;
            // Calculate the result
            for (auto s : sumsAlongThePath) {
                result += (sum - s == givenSum);
            }
            // End
            sumsAlongThePath.push_back(sum);

            if (node->left == NULL && node->right == NULL) {

            } else {
                visit(node->left, sum);
                visit(node->right, sum);
            }
            sumsAlongThePath.pop_back();
        }
    }
    int pathSum(TreeNode* root, int sum) {
        givenSum = sum;
        sumsAlongThePath.push_back(0);
        visit(root, 0);
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: binary search tree
 * 
 * */

