/* Problem url: https://leetcode.com/problems/valid-palindrome-ii/
 * Code by: ldcduc
 * */
class Solution {
public:
    bool validPalindrome(string s) {
        int count = 0, len = s.length();
        vector<int> ignore;
        for (int i=0; i<len/2; ++i) {
            if (s[i] != s[len - i - 1]) {
                ignore.push_back(i);
                ignore.push_back(len - i - 1);
                break;
            }
        }
        if (ignore.empty())
            return true;
        int true1 = true, true2 = true;
        for (int i=0, j=len - 1; i<j; ++i, --j) {
            if (i == ignore[0])
                ++i;
            if (i == len) break;
            if (s[i] != s[j])
                true1 = false;
        }
        for (int i=0, j=len - 1; i<j; ++i, --j) {
            if (j == ignore[1])
                --j;
            if (j < 0) break;
            if (s[i] != s[j])
                true2 = false;
        }
        return true1 || true2;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: implementation
 * 
 * */
