/* Problem url: https://leetcode.com/problems/longest-palindromic-substring
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        string result = s.substr(0, 1);
        vector<vector<bool>> dp(n, vector<bool> (n, 0));
        for (int i = 0; i < n; ++ i) {
            dp[i][i] = true;
        }
        for (int i = 1; i < n; ++ i) {
            dp[i - 1][i] = s[i - 1] == s[i];
            if (dp[i - 1][i]) {
                result = s.substr(i - 1, 2);
            }
        }
        for (int i = 0; i < n; ++ i) {
            for (int offset = 1; offset < n; ++ offset) {
                int l = i - offset, r = i + offset;
                for (int k = 0; k < 2; ++ k) {
                    l -= k;
                    if (0 <= l && r < n) {
                        dp[l][r] = dp[l + 1][r - 1] && s[l] == s[r];    
                        if (dp[l][r] && r - l + 1 > result.length()) {
                            result = s.substr(l, r - l  + 1);
                        }
                    }
                }
            }        
        }
        return result;
    }
};
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        string result = s.substr(0, 1);
        vector<vector<bool>> dp(n, vector<bool> (n, 0));
        for (int i = 0; i < n; ++ i) {
            dp[i][i] = true;
        }
        for (int i = 1; i < n; ++ i) {
            dp[i - 1][i] = s[i - 1] == s[i];
            if (dp[i - 1][i]) {
                result = s.substr(i - 1, 2);
            }
        }
        for (int len = 3; len <= n; ++ len) {
            for (int i = len - 1; i < n; ++ i) {
                dp[i - len + 1][i] = dp[i - len + 2][i - 1] && s[i - len + 1] == s[i];
                if (dp[i - len + 1][i] && len > result.length()) {
                    result = s.substr(i - len + 1, len);
                }
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
