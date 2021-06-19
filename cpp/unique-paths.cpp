/* Problem url: https://leetcode.com/problems/unique-paths
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, 0));
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (i + j == 0) {
                    dp[i][j] = 1;    
                } else {
                    if (i > 0) {
                        dp[i][j] += dp[i - 1][j];
                    }
                    if (j > 0) {
                        dp[i][j] += dp[i][j - 1];
                    }
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: dynamic programming
 * 
 * */
