/* Problem url: https://leetcode.com/problems/replace-all-s-to-avoid-consecutive-repeating-characters
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    string modifyString(string s) {
        for (int i = 0; i < s.length(); ++ i) {
            if (s[i] == '?') {
                int ok = false;    
                char c;
                for (c = 'a'; c <= 'z' && !ok; ++ c) {
                    ok = i == 0 || s[i - 1] != c;
                    ok &= i + 1 == s.length() || s[i + 1] != c;
                }
                s[i] = c - 1;
            }
        }
        return s;    
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: string, implementation
 * 
 * */
