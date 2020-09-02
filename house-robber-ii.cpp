/* Problem url: https://leetcode.com/problems/house-robber-ii
 * Code by: ldcduc
 * */
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n > 0) {
            vector<int> dp[2];
            dp[0].resize(n); // dp nums[0] is not chosen
            dp[1].resize(n); // dp chosen nums[0]
            dp[0][0] = 0;
            dp[1][0] = nums[0];
            if (n > 1) {
                dp[0][1] = nums[1];
                dp[1][1] = dp[1][0];
            }
            for (int i = 2; i < n; ++ i) {
                if (i < n - 1) {
                    dp[0][i] = max(dp[0][i - 1], dp[0][i - 2] + nums[i]);
                    dp[1][i] = max(dp[1][i - 1], dp[1][i - 2] + nums[i]);
                } else {
                    dp[0][i] = max(dp[0][i - 1], dp[0][i - 2] + nums[i]);
                    dp[1][i] = dp[1][i - 1];
                }
            }
            return max(dp[0][n - 1], dp[1][n - 1]);
        }
        return 0;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: dynamic programming
 * 
 * */

