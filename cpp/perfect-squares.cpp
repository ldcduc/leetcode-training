/* Problem url: https://leetcode.com/problems/perfect-squares
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int numSquares(int n) {
        int sqrt_ = sqrt(n);    
        vector<int> dp(n + 1, 0);
        for (int val = 1; val <= n; ++ val) {
            dp[val] = n; // infinity
            for (int i = 1; i <= sqrt_; ++ i) {
                if (val - i * i >= 0) {
                    dp[val] = min(dp[val], dp[val - i * i] + 1);
                } else {
                    break;
                }
            }
        }
        return dp[n];
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: dynamic programming
 * 
 * */
