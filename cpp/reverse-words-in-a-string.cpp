/* Problem url: https://leetcode.com/problems/reverse-words-in-a-string
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    string reverseWords(string s) {
        string result = "", word;    
        s += ' ';
        stack<string> S;
        for (int i = 0; i < s.length(); ++ i) {
            if ('a' <= s[i] && s[i] <= 'z' || 'A' <= s[i] && s[i] <= 'Z' || '0' <= s[i] && s[i] <= '9') {
                word += s[i];    
            } else {
                if (word.size() > 0) {
                    S.push(word);
                }
                word = "";
            }       
        } 
        while (!S.empty()) {
            result += S.top();
            result += ' ';
            S.pop();
        }
        result.erase(result.size() - 1, 1);
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: string
 * 
 * */
