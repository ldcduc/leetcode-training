/* Problem url: https://leetcode.com/problems/repeated-substring-pattern
 * Code by: ldcduc
 * */
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return ((s + s).substr(1, 2 * s.length() - 2).find(s) != -1);
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: string, fun, trick
 * 
 * */

