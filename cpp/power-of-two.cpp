/* Problem url: https://leetcode.com/problems/power-of-two
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0) && (n == (n & -n));
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: bit manipulation
 * 
 * */
