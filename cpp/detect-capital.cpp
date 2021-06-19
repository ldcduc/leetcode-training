/* Problem url: https://leetcode.com/problems/detect-capital
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.length(), cnt = 0;    
        for (int i = 0; i < n; ++ i) {
            cnt += 'A' <= word[i] && word[i] <= 'Z';
        }
        return cnt == 0 || (cnt == 1 && 'A' <= word[0] && word[0] <= 'Z') || cnt == n;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: string
 * 
 * */
