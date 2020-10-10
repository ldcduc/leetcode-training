/* Problem url: https://leetcode.com/problems/factorial-trailing-zeroes
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int trailingZeroes(int n) {
        int cnt2 = 0, cnt5 = 0;
        for (int i = 2; i <= n; ++ i) {
            int num = i;
            for (; num % 2 == 0; ++ cnt2, num /= 2);
            for (; num % 5 == 0; ++ cnt5, num /= 5);
        }
        return min(cnt2, cnt5);
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: math
 * 
 * */
