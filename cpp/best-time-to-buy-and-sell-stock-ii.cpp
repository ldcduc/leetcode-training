/* Problem url: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii
 * Code by: ldcduc
 * */
/* Begin of Solution */
class SimpleSolution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        for (int i = 1; i < prices.size(); ++ i) {
            if (prices[i - 1] < prices[i]) {
                result += prices[i] - prices[i - 1];
            }
        }
        return result;
    }
};
class DynamicProgrammingSolution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        if (prices.size()) {
            vector<int> dp(prices.size()), tmp(prices.size());
            for (int i = 0; i < prices.size(); ++ i) {
                dp[i] = i > 0 ? prices[i] + tmp[i - 1] : 0; 
                result = max(result, dp[i]);
                if (i == 0) {
                    tmp[i] = -prices[i];
                } else {
                    dp[i] = max(dp[i], dp[i - 1]);
                    tmp[i] = -prices[i] + dp[i - 1];
                    tmp[i] = max(tmp[i], tmp[i - 1]);
                }
            } 
        }    
        return result;
    }
};
/*
let dp[i] = maximum profit if sell stock on day i
original dp[i] = max( every j < i | dp[j - 1] + prices[i] - prices[j])
then     dp[i] = max(dp[i], dp[i - 1])

However
  dp[j - 1] + prices[i] - prices[j]
= prices[i] - prices[j] + dp[j - 1]
                      tmp[j]
let tmp[j] = -prices[j] + dp[j - 1]
let tmp[j] = max(tmp[j], tmp[j - 1])
*/
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: dynamic programming
 * 
 * */
