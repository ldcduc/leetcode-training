/* Problem url: https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int minimumLength(string s) {
        int l = 0, r = s.length() - 1;
        while (l < r && s[l] == s[r]) {
            while (l + 1 < r && s[l + 1] == s[l]) {
                ++ l;
            }
            while (l < r - 1 && s[r - 1] == s[r]) {
                -- r;
            }
            ++ l; -- r;
        }
        return r - l + 1;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: string
 * 
 * */
