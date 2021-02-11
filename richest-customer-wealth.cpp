/* Problem url: https://leetcode.com/problems/richest-customer-wealth
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int m = accounts.size(), result = 0;
        for (int i = 0; i < m; ++ i) {
            int total = 0;
            for (auto num : accounts[i]) {
                total += num;
            }
            result = max(result, total);
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
