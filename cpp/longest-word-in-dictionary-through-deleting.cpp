/* Problem url: https://leetcode.com/problems/longest-word-in-dictionary-through-deleting
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string result = "";    
        int res_len = 0;
        int n = s.length();
        for (auto word : d) {
            int id = 0, len = word.length();
            for (int i = 0; i < n && id < len; ++ i) {
                if (s[i] == word[id]) {
                    ++ id;
                }    
            }
            if (id == len) {
                if (res_len < len) {
                    result = word;
                    res_len = len;
                } else if (res_len == len && word < result) {
                    result = word;
                }
            }
        } 
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: string
 * 
 * */
