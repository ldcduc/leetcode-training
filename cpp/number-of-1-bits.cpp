/* Problem url: https://leetcode.com/problems/number-of-1-bits
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        while (n) {
            ++ result;
            n -= n & -n;
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: bit manipulation
 * 
 * */
