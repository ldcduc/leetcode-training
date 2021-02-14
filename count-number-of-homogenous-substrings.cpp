/* Problem url: https://leetcode.com/problems/count-number-of-homogenous-substrings
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int countHomogenous(string s) {
        int result = 0;
        char c = s[0];
        int cnt = 0;
        s += '#';
        const int mod = 1e9 + 7;
        for (int i = 0; i < s.length(); ++ i) {
            if (s[i] == c) {
                ++ cnt;
            } else {
                result = (result + 1ll * cnt * (cnt + 1) / 2) % mod;
                c = s[i];
                cnt = 1;
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
