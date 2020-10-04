/* Problem url: https://leetcode.com/problems/add-digits
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int addDigits(int num) {
        while (num > 9) {
            int newNum = 0;    
            for (; num; newNum += num % 10, num /= 10);
            num = newNum;
        }        
        return num;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: easy
 * 
 * */
