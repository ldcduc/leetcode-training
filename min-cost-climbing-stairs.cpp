/* Problem url: https://leetcode.com/problems/min-cost-climbing-stairs
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, 0);
        for (int i = 2; i <= n; ++ i) {
            dp[i] = dp[i - 1] + cost[i - 1];
            if (dp[i - 2] + cost[i - 2] < dp[i]) {
                dp[i] = dp[i - 2] + cost[i - 2];
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
