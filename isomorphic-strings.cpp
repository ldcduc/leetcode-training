/* Problem url: https://leetcode.com/problems/isomorphic-strings
 * Code by: ldcduc
 * */
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> f1(256);
        vector<int> f2(256);
        for (int i = 0; i < 256; ++ i) {
            f1[i] = f2[i] = -1;
        }
        int n = s.length();
        for (int i = 0; i < n; ++ i) {
            if (f1[s[i]] == -1 && f2[t[i]] == -1) {
                f1[s[i]] = t[i];
                f2[t[i]] = s[i];
            } else {
                if (f1[s[i]] != t[i] || f2[t[i]] != s[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: string, implementation
 * 
 * */

