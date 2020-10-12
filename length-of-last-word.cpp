/* Problem url: https://leetcode.com/problems/length-of-last-word
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int lengthOfLastWord(string s) {
        int result = 0;
        for (int i = s.length() - 1; i >= 0; -- i) {
            if (s[i] != ' ') {
                ++ result;
            } else if (result > 0) {
                break;
            }
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: 
 * 
 * */
