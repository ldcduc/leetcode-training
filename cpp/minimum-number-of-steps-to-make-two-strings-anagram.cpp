/* Problem url: https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> f1(26, 0), f2(26, 0);
        for (auto ch : s) {
            ++ f1[ch - 'a']; 
        }
        for (auto ch : t) {
            ++ f2[ch - 'a'];
        }
        int cnt = 0;
        for (int i = 0; i < 26; ++ i) {
            cnt += abs(f1[i] - f2[i]);
        }
        return cnt / 2; 
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: string, counting
 * 
 * */
