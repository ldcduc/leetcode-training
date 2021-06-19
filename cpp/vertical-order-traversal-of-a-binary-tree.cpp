/* Problem url: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;     
        map<int, map<int, vector<int>>> M;
        queue<pair<TreeNode*, pair<int, int>>> Q;
        Q.push({root, {0, 0}});
        while (!Q.empty()) {
            TreeNode* node = Q.front().first;
            int row = Q.front().second.first;
            int col = Q.front().second.second;
            Q.pop();
            M[col][row].push_back(node->val);
            if (node->left) {
                Q.push({node->left, {row + 1, col - 1}});
            }
            if (node->right) {
                Q.push({node->right, {row + 1, col + 1}});
            }
        }
        for (auto item : M) {
            vector<int> tmp;
            for (auto item2 : item.second) {
                sort(item2.second.begin(), item2.second.end());
                for (auto item3 : item2.second) {
                    tmp.push_back(item3);
                }
            }
            result.push_back(tmp);    
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: map
 * 
 * */
