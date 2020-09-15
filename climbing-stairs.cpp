/* Problem url: https://leetcode.com/problems/climbing-stairs
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);      
        dp[0] = 1;
        for (int i = 1; i <= n; ++ i) {
            dp[i] = dp[i - 1];
            if (i > 1) {
                dp[i] += dp[i - 2];
            }
        }
        return dp.back();
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: dynamic programming
 * 
 * */
