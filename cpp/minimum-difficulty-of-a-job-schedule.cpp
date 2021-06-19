/* Problem url: https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        vector<vector<int>> dp(n, vector<int>(d, -1));
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < min(d, i + 1); ++ j) {
                if (j == 0) {
                    dp[i][j] = 0;
                    for (int k = i; k >= 0; -- k) {
                        dp[i][j] = max(dp[i][j], jobDifficulty[k]);
                    }    
                } else {
                    int maxDifficulty = 0;
                    dp[i][j] = 1e9; // infinity
                    for (int k = i; k > 0; -- k) {
                        maxDifficulty = max(maxDifficulty, jobDifficulty[k]);
                        if (dp[k - 1][j - 1] != -1) {
                            dp[i][j] = min(dp[i][j], dp[k - 1][j - 1] + maxDifficulty);
                        }
                    }
                }
            }
        }
        int t = dp[n - 1][d - 1];
        return -1 < t && t < 1e9 ? t : -1;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: dynamic programming
 * 
 * */
