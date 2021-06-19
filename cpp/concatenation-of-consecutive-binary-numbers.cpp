/* Problem url: https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    void add2(int &a, int b) {
        int modulo = 1e9 + 7;    
        a = (1ll * a * 2 + b) % modulo;
    }
    int concatenatedBinary(int n) {
        int result = 0;
        int modulo = 1e9 + 7;
        for (int val = 1; val <= n; ++ val) {
            int x = val;
            string s = "";
            while (x) {
                s += (x & 1) + '0';
                x >>= 1;
            }
            for (int i = s.length() - 1; i >= 0; -- i) {
                add2(result, s[i] - '0');
            }
        }    
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: math
 * 
 * */
