/* Problem url: https://leetcode.com/problems/longest-common-subsequence
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
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.length(), len2 = text2.length();
        vector<vector<int>> dp(len1, vector<int> (len2, 0));
        for (int i = 0; i < len1; ++ i) {
            for (int j = 0; j < len2; ++ j) {
                dp[i][j] = text1[i] == text2[j];
                if (i - 1 >= 0) {
                    maximize(dp[i][j], dp[i - 1][j]);
                    if (j - 1 >= 0) {
                        maximize(dp[i][j], dp[i - 1][j - 1] + (text1[i] == text2[j]));
                    }
                }
                if (j - 1 >= 0) {
                    maximize(dp[i][j],dp[i][j - 1]);
                }
            }
        }
        return dp[len1 - 1][len2 - 1];
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: dynamic programming
 * 
 * */
