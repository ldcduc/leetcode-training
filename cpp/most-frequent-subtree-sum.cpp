/* Problem url: https://leetcode.com/problems/most-frequent-subtree-sum
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
    vector<int> sums;

    int calSum(TreeNode* node) {
        if (node) {
            int sum = node->val + calSum(node->left) + calSum(node->right);
            sums.push_back(sum);
            return sum;
        }
        return 0;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> result;
        calSum(root);
        if (!sums.empty()) {
            sort(sums.begin(), sums.end());
            int sum = sums[0], cnt = 0, maxCnt = 0;
            for (auto item : sums) {
                if (item == sum) {
                    ++cnt;
                } else {
                    if (cnt > maxCnt) {
                        result.clear();
                        result.push_back(sum);
                        maxCnt = cnt;
                    } else if (cnt == maxCnt) {
                        result.push_back(sum);
                    }
                    cnt = 1;
                    sum = item;
                }
            }
            if (cnt > maxCnt) {
                result.clear();
                result.push_back(sum);
                maxCnt = cnt;
            } else if (cnt == maxCnt) {
                result.push_back(sum);
            }
        }
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: tree traversal
 * 
 * */

