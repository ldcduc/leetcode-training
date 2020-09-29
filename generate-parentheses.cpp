/* Problem url: https://leetcode.com/problems/generate-parentheses
 * Code by: ldcduc
 * */
class Solution {
public:
    void recursion(vector<string> &result, string &pattern, int n, int index, int cntOpen = 0) {
        if (index == n) {
            if (cntOpen == 0) {
                result.push_back(pattern);
            }
            return;
        }
        if (index + cntOpen - 1 < n) {
            pattern[index] = '(';
            recursion(result, pattern, n, index + 1, cntOpen + 1);
        }
        if (cntOpen) {
            pattern[index] = ')';
            recursion(result, pattern, n, index + 1, cntOpen - 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string pattern;
        pattern.resize(2 * n);
        recursion(result, pattern, 2 * n, 0);
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: recursion
 * 
 * */

