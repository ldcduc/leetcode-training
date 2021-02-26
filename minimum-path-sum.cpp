/* Problem url: https://leetcode.com/problems/minimum-path-sum
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int> > dp(m, vector<int> (n, 54321));
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                dp[i][j] = (i == 0 && j == 0) ? grid[i][j] : 54321;
                if (i > 0) {
                    dp[i][j] = min(dp[i][j], grid[i][j] + dp[i - 1][j]);
                }
                if (j > 0) {
                    dp[i][j] = min(dp[i][j], grid[i][j] + dp[i][j - 1]);
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
