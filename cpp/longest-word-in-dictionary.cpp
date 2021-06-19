/* Problem url: https://leetcode.com/problems/longest-word-in-dictionary
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    string longestWord(vector<string>& words) {
        string result = "";
        unordered_map<string, bool> M;    
        sort(words.begin(), words.end());
        for (int i = 0; i < words.size(); ++ i) {
            if (words[i].length() == 1) {
                M[words[i]] = true;    
                if (words[i].length() > result.length()) {
                    result = words[i];
                }
            } else {
                if (M.count(words[i].substr(0, words[i].length() - 1))) {
                    M[words[i]] = true;
                    if (words[i].length() > result.length()) {
                        result = words[i];
                    }
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
