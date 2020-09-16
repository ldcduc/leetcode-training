/* Problem url: https://leetcode.com/problems/n-th-tribonacci-number
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    vector<int> dp;
    Solution() {
        dp.resize(38, 0);
    }
    int tribonacci(int n) {
        if (n < 3) {
            return !!n;
        }      
        return dp[n] ? dp[n] : dp[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: easy
 * 
 * */
