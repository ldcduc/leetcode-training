/* Problem url: https://leetcode.com/problems/power-of-three
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n > 0) {
            for (; n % 3 == 0; n /= 3);
            return n == 1;
        }
        return false;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: iteration
 * 
 * */
