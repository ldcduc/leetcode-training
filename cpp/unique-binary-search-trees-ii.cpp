/* Problem url: https://leetcode.com/problems/unique-binary-search-trees-ii
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
    vector<TreeNode*> generateTrees(int l, int r) {
        if (l <= r) {
            vector<TreeNode*> result;
            for (int i = l; i <= r; ++ i) {
                for (auto lTree : generateTrees(l, i - 1)) {
                    for (auto rTree : generateTrees(i + 1, r)) {
                        result.push_back(new TreeNode(i));
                        result.back()->left = lTree;
                        result.back()->right = rTree;
                    }
                }
            }    
            return result;
        }
        return vector<TreeNode*> {NULL};
    }
    vector<TreeNode*> generateTrees(int n) {
        return n > 0 ? generateTrees(1, n) : vector<TreeNode*>();        
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: binary search tree, recursion
 * 
 * */
