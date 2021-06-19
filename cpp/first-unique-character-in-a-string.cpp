/* Problem url: https://leetcode.com/problems/first-unique-character-in-a-string
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int firstUniqChar(string s) {
        int result = s.length();
        vector<vector<int>> appearance(26);
        for (int i = s.length() - 1; i >= 0; -- i) {
            appearance[s[i] - 'a'].push_back(i);
        }
        for (int i = 0; i < 26; ++ i) {
            if (appearance[i].size() == 1) {
                result = min(result, appearance[i][0]);
            }
        }
        return result < s.length() ? result : -1;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: hash table, string
 * 
 * */
