/* Problem url: https://leetcode.com/problems/filling-bookcase-shelves
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int n = books.size();
        vector<int> dp(n + 1);      
        for (int i = 1; i <= n; ++ i) {
            int sum = 0, max_height = books[i - 1][1];
            dp[i] = dp[i - 1] + books[i - 1][1];
            
            // Optimization
            for (int j = i - 1; sum <= shelf_width && j >= 0; -- j) {
                sum += books[j][0];
                max_height = max(max_height, books[j][1]);
                if (sum <= shelf_width) {
                    dp[i] = min(dp[i], dp[j] + max_height);    
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
