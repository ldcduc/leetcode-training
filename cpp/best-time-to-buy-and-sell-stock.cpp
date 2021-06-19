/* Problem url: https://leetcode.com/problems/best-time-to-buy-and-sell-stock
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        if (prices.size()) {
            int maxPrice = prices.back();
            for (int i = prices.size() - 1; i >= 0; -- i) {
                result = max(result, maxPrice - prices[i]);
                maxPrice = max(maxPrice, prices[i]);
            }
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: array
 * 
 * */
