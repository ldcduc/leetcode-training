/* Problem url: https://leetcode.com/problems/generate-parentheses
 * Code by: ldcduc
 * */
class Solution {
public:
    vector<string> result;
    string s;

    void generate(int index, int open, int n) {
        if (index == n) {
            result.push_back(s);
        } else if (n - index >= open) {
            if (n - index > open) {
                s[index] = '(';
                generate(index + 1, open + 1, n);
            }
            if (open > 0) {
                s[index] = ')';
                generate(index + 1, open - 1, n);
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        n *= 2;
        for (int i = 0; i < n; ++ i) {
            s.push_back(' ');
        }
        generate(0, 0, n);
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: recursion
 * 
 * */

