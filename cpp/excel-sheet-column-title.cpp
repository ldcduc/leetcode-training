/* Problem url: https://leetcode.com/problems/excel-sheet-column-title/
 * Code by: ldcduc
 * */
class Solution {
public:
    string convertToTitle(int n) {
        vector<char> chars;
        while (n) {
            int mod = (n % 26) ? n % 26 : 26;
            chars.push_back((char)('A' + mod - 1));
            n = n / 26 - !(n % 26);
        } 
        string result = "";
        for (int i = chars.size() - 1; i >= 0; --i) 
            result += chars[i];
        return result; 
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: implementation, math
 * 
 * */

