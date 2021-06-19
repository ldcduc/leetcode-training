/* Problem url: https://leetcode.com/problems/combination-sum-iv
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<unsigned long long> dp(target + 1, 0);
        dp[0] = 1;
        for (int val = 1; val <= target; ++ val) {
            for (int i = 0; i < nums.size(); ++ i) {
                if (val - nums[i] >= 0) {
                    dp[val] += dp[val - nums[i]];
                } else {
                    break;
                } 
            }
        }
        return dp[target];
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: dynamic programming
 * 
 * */
