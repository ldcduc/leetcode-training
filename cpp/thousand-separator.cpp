/* Problem url: https://leetcode.com/problems/thousand-separator
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    string thousandSeparator(int n) {
        if (n) {
            string s = "";
            int cnt = 0;
            while (n) {
                s = char('0' + n % 10) + s;
                ++ cnt;
                n /= 10;
                if (cnt % 3 == 0 && n) {
                    s = '.' + s;        
                }
            }
            return s;
        } 
        return "0";
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: string, implementation
 * 
 * */
