/* Problem url: https://leetcode.com/problems/power-of-four
 * Code by: ldcduc
 * */
class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num == 1) return true;
        for (; num > 1; num >>= 2) {
            if (num % 4) return false;
        }
        return num == 1;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: math, implementation
 * 
 * */

