/* Problem url: https://leetcode.com/problems/bag-of-tokens
 * Code by: ldcduc
 * */
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        int result = 0, point = 0;
        sort(tokens.begin(), tokens.end());
        int i = 0, j = tokens.size() - 1;
        while (i <= j) {
            if (P >= tokens[i]) {
                P -= tokens[i ++];
                ++ point;
            } else if (point) {
                P += tokens[j --];
                -- point;
            } else {
                break;
            }
            if (point > result) {
                result = point;
            }
        }
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: greedy
 * 
 * */

