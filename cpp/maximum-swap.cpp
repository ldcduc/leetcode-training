/* Problem url: https://leetcode.com/problems/maximum-swap
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int maximumSwap(int num) {
        int result = num, powMax, pow = 1, maxDigit = -1;
        int tmp = num;
        while (tmp) {
            if (tmp % 10 > maxDigit) {
                maxDigit = tmp % 10;
                powMax = pow;
            } else {
                result = max(result, num - (tmp % 10 - maxDigit) * pow + (tmp % 10 - maxDigit) * powMax);
            }
            pow *= 10;
            tmp /= 10;
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: math, implementation
 * 
 * */
