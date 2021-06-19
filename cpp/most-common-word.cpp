/* Problem url: https://leetcode.com/problems/most-common-word
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        map<string, int> M;
        paragraph += ' ';
        for (auto word : banned) {
            M[word] = -1000;
        }
        int len = paragraph.length();
        for (int i = 0; i < len; ++ i) {
            if ('A' <= paragraph[i] && paragraph[i] <= 'Z') {
                paragraph[i] += 'a' - 'A';
            } else if (paragraph[i] < 'a' || paragraph[i] > 'z') {
                paragraph[i] = ' ';
            }
        } 
        int start = -1;
        while (start < len - 1) {
            int nextSpace = paragraph.find(' ', start + 1);
            if (nextSpace != start + 1) {
                string word = paragraph.substr(start + 1, nextSpace - start - 1);
                ++M[word];
            }
            start = nextSpace;
        }
        string result = "";
        bool optimized = false;
        int cnt;
        for (auto item : M) {
            if (!optimized || item.second > cnt) {
                cnt = item.second;
                result = item.first;
                optimized = true;
            }    
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: string, data structure
 * 
 * */
