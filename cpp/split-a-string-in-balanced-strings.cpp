/* Problem url: https://leetcode.com/problems/split-a-string-in-balanced-strings
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int balancedStringSplit(string s) {
        int result = 0;
        int point = 0;
        for (auto ch : s) {
            point += ch == 'L' ? -1 : 1;
            if (point == 0) {
                ++result;
            }
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: easy, string
 * 
 * */
