/* Problem url: https://leetcode.com/problems/valid-anagram
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: sorting
 * 
 * */
