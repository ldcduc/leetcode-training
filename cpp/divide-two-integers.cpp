/* Problem url: https://leetcode.com/problems/divide-two-integers
 * Code by: ldcduc
 * */
class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = (dividend < 0) ^ (divisor < 0);      
        dividend = abs(dividend);
        divisor = abs(divisor);
        long long quotient = 0;
        long long tmp = 0;
        for (int i = 31; i >= 0; --i) {
            if (tmp + (((long long) divisor) << i) <= dividend) {
                tmp += ((long long) divisor) << i; 
                quotient |= 1ll << i;
            }
        }
        
        if (sign) {
            return (-quotient < -2147483648) ? 2147483647 : -quotient;
        }
        return (quotient > 2147483647) ? 2147483647 : quotient;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: math, bit manipulation
 * 
 * */
