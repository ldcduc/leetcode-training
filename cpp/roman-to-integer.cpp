/* Problem url: https://leetcode.com/problems/roman-to-integer
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int romanToInt(string s) {
        int table[256], len = s.length();
        table['I'] = 1;
        table['V'] = 5;
        table['X'] = 10;
        table['L'] = 50;
        table['C'] = 100;
        table['D'] = 500;
        table['M'] = 1000;
        int ans = 0;
        for (int i = 0; i < len - 1; ++ i) {
            if (table[s[i]] < table[s[i + 1]]) {
                ans -= table[s[i]];
            } else {
                ans += table[s[i]];
            }   
        }
        ans += table[s[len - 1]];
        return ans;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: string
 * 
 * */
