/* Problem url: https://leetcode.com/problems/binary-number-with-alternating-bits
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev = ~(n & 1), result = 1;    
        while (n) {
            result &= prev ^ (n & 1);
            prev = n & 1;
            n >>= 1;
        } 
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: 
 * 
 * */
