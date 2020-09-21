/* Problem url: https://leetcode.com/problems/reverse-integer
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int reverse(int x) {
        bool negative = (x < 0);
        long long result = 0;
        x = abs(x);
        while (x) {
            result = result * 10 + x % 10;
            x /= 10;
        }
        result = negative ? -result : result;
        return (result < -2147483648 || result > 2147483647) ? 0 : result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: easy
 * 
 * */
