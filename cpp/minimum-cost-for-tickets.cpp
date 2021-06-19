/* Problem url: https://leetcode.com/problems/minimum-cost-for-tickets
 * Code by: ldcduc
 * */
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366, 0);
        for (auto day : days) {
            dp[day] = 1;
        }
        for (int day = 1; day <= 365; ++ day) {
            if (dp[day]) {
                dp[day] = dp[day - 1] + costs[0];
            } else {
                dp[day] = dp[day - 1];
            }

            if (day - 7 >= 0 && dp[day - 7] + costs[1] < dp[day]) {
                dp[day] = dp[day - 7] + costs[1];
            }
            if (day - 30 >= 0 && dp[day - 30] + costs[2] < dp[day]) {
                dp[day] = dp[day - 30] + costs[2];
            }
        }
        return dp[365];
    }
};

/*
 * Comment by ldcduc
 * Suggested tags: math, careful
 * 
 * */

