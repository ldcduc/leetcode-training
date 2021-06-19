/* Problem url: https://leetcode.com/problems/beautiful-arrangement
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int recursion(int n, int i, int mask) {
        if (i == n + 1) {
            return 1;   
        } 
        int result = 0;
        for (int candidate = 1; candidate <= n; ++ candidate) {
            if (!(mask >> (candidate - 1) & 1) && (candidate % i == 0 || i % candidate == 0)) { // candidate have not been used && beautiful-condition is true
                int new_mask = mask | (1 << (candidate - 1));
                result += recursion(n, i + 1, new_mask);     
            }
        }
        return result;
    }
    int countArrangement(int n) {
        return recursion(n, 1, 0);    
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: 
 * 
 * */
