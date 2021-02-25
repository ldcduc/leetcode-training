/* Problem url: https://leetcode.com/problems/merge-strings-alternately
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";    
        int i1 = 0, i2 = 0;
        while (i1 < word1.length() && i2 < word2.length()) {
            result += word1[i1 ++];
            result += word2[i2 ++];
        }
        for (int i = i1; i < word1.length(); ++ i) {
            result += word1[i];    
        }
        for (int i = i2; i < word2.length(); ++ i) {
            result += word2[i]; 
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
