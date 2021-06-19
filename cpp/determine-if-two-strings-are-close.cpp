/* Problem url: https://leetcode.com/problems/determine-if-two-strings-are-close
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> f1(26, 0), f2(26, 0);
        for (auto ch : word1) {
            ++ f1[ch - 'a'];
        }
        for (auto ch : word2) {
            ++ f2[ch - 'a'];
        }
        for (int i = 0; i < 26; ++ i) {
            if (!!f1[i] ^ !!f2[i]) {  // True if 0, 0 or gt0, gt0
                return false;    
            }
        }
        sort(f1.begin(), f1.end());
        sort(f2.begin(), f2.end());
        for (int i = 0; i < 26; ++ i) {
            if (f1[i] != f2[i]) {
                return false;
            }
        }
        return true;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: string, sorting
 * 
 * */
