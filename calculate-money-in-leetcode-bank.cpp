/* Problem url: https://leetcode.com/problems/calculate-money-in-leetcode-bank
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int totalMoney(int n) {
        int result = 0, monday = 0, today = 0;    
        for (int i = 0; i < n; ++ i) {
            if (i % 7 == 0) {
                ++ monday;
                today = monday; 
            } else {
                ++ today;    
            }
            result += today;
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: iteration
 * 
 * */
