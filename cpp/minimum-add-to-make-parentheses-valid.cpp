/* Problem url: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int minAddToMakeValid(string S) {
        int result = 0, open = 0;
        for (int i = 0; i < S.length(); ++ i) {
            if (S[i] == '(') {
                ++ open; 
            } else {
                if (open == 0) { 
                    ++ result;
                } else {
                    -- open;
                }    
            }
        } 
        result += open;
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: easy
 * 
 * */
