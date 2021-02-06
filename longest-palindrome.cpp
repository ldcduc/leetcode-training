/* Problem url: https://leetcode.com/problems/longest-palindrome
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> cnt(256, 0);
        for (int i = 0; i < s.length(); ++ i) {
            ++ cnt[s[i]];
        }
        int odd = 0;
        int result = 0;
        for (int c = 0; c < 256; ++ c) {
            if (cnt[c]) {
                if (cnt[c] % 2) {
                    odd = 1;
                    result += cnt[c] - 1;
                } else {
                    result += cnt[c];
                }
            }
        }
        result += odd;
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: palindrome, string
 * 
 * */
