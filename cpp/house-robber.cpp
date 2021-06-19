/* Problem url: https://leetcode.com/problems/house-robber
 * Code by: ldcduc
 * */
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1);
        dp[0] = 0;
        if (nums.size()) {
            dp[1] = nums[0];
        }
        for (int i = 2; i <= n; ++ i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }
        return dp[n];
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: dynamic programming
 * 
 * */

