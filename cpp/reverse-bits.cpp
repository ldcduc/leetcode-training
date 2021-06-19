/* Problem url: https://leetcode.com/problems/reverse-bits
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; ++ i) {
            result = (result << 1) | (n & 1);
            n >>= 1;
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
