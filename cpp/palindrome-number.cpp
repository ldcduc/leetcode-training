/* Problem url: https://leetcode.com/problems/palindrome-number
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }    
        long long tmpX = x, newX = 0;
        while (tmpX) {
            newX = newX * 10 + tmpX % 10;
            tmpX /= 10;
        }
        return newX == x;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: palindrome
 * 
 * */
