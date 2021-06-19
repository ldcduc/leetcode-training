/* Problem url: https://leetcode.com/problems/happy-number
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    bool isHappy(int n) {
        int cnt = 0;
        while (n != 1 && cnt < 100) {
            ++ cnt;
            int newN = 0;
            while (n) {
                newN += (n % 10) * (n % 10);
                n /= 10;
            }
            n = newN;
        }    
        return n == 1;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: easy
 * 
 * */
