/* Problem url: https://leetcode.com/problems/smallest-integer-divisible-by-k
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int smallestRepunitDivByK(int K) {
        int length = 1, remainder = 1;
        while (length < 1000000 && remainder % K) {
            ++ length;
            remainder = (remainder * 10 + 1) % K;
        } 
        return remainder % K ? -1 : length;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: math
 * 
 * */
