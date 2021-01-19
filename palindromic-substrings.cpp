/* Problem url: https://leetcode.com/problems/palindromic-substrings
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int result = n;
        vector<vector<bool>> dp(n, vector<bool> (n, 0));
        for (int i = 0; i < n; ++ i) {
            dp[i][i] = true;
        }
        for (int i = 1; i < n; ++ i) {
            dp[i - 1][i] = s[i - 1] == s[i];
            result += dp[i - 1][i];
        }
        for (int len = 3; len <= n; ++ len) {
            for (int i = len - 1; i < n; ++ i) {
                dp[i - len + 1][i] = dp[i - len + 2][i - 1] && s[i - len + 1] == s[i];
                result += dp[i - len + 1][i];
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
