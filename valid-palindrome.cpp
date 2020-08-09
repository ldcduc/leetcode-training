/* Problem url: https://leetcode.com/problems/valid-palindrome/
 * Code by: ldcduc
 * */
class Solution {
public:
    int flag[256];
    Solution() {
        for (int i=0; i<256; ++i)
            flag[i] = ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z') || (i >= '0' && i <= '9'));
    }
    char lowerCase(char c) {
        return (c >= 'A' && c <= 'Z') ? (char)(c - 'A' + 'a') : (char) c;
    }
    bool isPalindrome(string s) {
        int len = s.length();
        int j = len - 1;
        for (int i=0; i<len; ++i)
            s[i] = lowerCase(s[i]);
        for (int i=0; i<j; ++i)
            if (flag[s[i]]) {
                while (i < j && !flag[s[j]]) {
                    --j;
                }
                if (s[i] != s[j])
                    return false;
                --j;
            }
        return true;
    }
};

/*
 * Comment by ldcduc
 * Suggested tags: implementation
 * 
 * */
