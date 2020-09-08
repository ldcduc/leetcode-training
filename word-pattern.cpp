/* Problem url: https://leetcode.com/problems/word-pattern
 * Code by: ldcduc
 * */
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> Map;
        unordered_map<string, char> Map2;
        int startIndex = 0;
        str += ' ';
        for (auto c : pattern) {
            int index = str.find(' ', startIndex);
            string token = str.substr(startIndex, index - startIndex);
            if (Map.count(c) == 0 && Map2.count(token) == 0) {
                Map[c] = token;
                Map2[token] = c;
            } else {
                if (Map[c] != token || Map2[token] != c) {
                    return false;
                }
            }
            startIndex = index + 1;
        }
        return (startIndex == str.length());
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: string, implementation
 * 
 * */

