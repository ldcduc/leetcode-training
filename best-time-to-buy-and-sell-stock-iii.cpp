/* Problem url: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
 * Code by: ldcduc
 * */
class Solution {
public:
    bool minimize(int &a, int b) {
        if (b < a) a = b;
        else return false;
        return true;
    }
    bool maximize(int &a, int b) {
        if (b > a) a = b;
        else return false;
        return true;
    }
    int maxProfit(vector<int>& prices) {
        int result = 0;
        int n = prices.size();
        int *f = new int [n], minn = 1e9, maxx;
        for (int i=0; i<n; ++i) {
            f[i] = 0;
            if (i > 0) maximize(f[i], f[i-1]);
            maximize(f[i], prices[i] - minn);
            minimize(minn, prices[i]);
            maximize(result, f[i]);
        }
        maxx = 0;
        for (int i=n-1; i>=0; --i) {
            int cur_result = -1; 
            maximize(cur_result, maxx - prices[i]);
            maximize(maxx, prices[i]);
            if (i > 1 && cur_result > 0) {
                maximize(result, cur_result + f[i-1]);
            }
        }
        delete [] f;
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: dp, 
 * 
 * */
