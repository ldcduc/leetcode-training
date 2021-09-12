/* Problem url: https://leetcode.com/problems/largest-odd-number-in-string
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    string largestOddNumber(string num) {
        string result = ""; 
        for (int i = num.length() - 1; i >= 0; -- i) {
            if ((num[i] - '0') % 2) {
                return num.substr(0, i + 1);
            }
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: string
 * 
 * */
