/* Problem url: https://leetcode.com/problems/longest-palindromic-subsequence
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    void maximize(int &a, int b) {
        if (b > a) {
            a = b;
        }
    }
    int longestPalindromeSubseq(string s) {
        int n = s.length(), result = 1;;
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for (int i = 0; i < n; ++ i) {
            dp[i][i] = 1;
        } 
        for (int i = 0; i < n - 1; ++ i) {
            dp[i][i + 1] = 1 + (s[i] == s[i + 1]);
            maximize(result, dp[i][i + 1]);
        }
        for (int len = 3; len <= n; ++ len) {
            for (int i = 0; i < n - len + 1; ++ i) {
                int j = i + len - 1;
                dp[i][j] = (s[i] == s[j]) * 2;
                maximize(dp[i][j], dp[i + 1][j - 1] + (s[i] == s[j]) * 2);
                maximize(dp[i][j], dp[i + 1][j]);
                maximize(dp[i][j], dp[i][j - 1]);
                maximize(result, dp[i][j]);
            }
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: dynamic programming, palindrome
 * 
 * */
