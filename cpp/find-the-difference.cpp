/* Problem url: https://leetcode.com/problems/find-the-difference
 * Code by: ldcduc
 * */
class Solution {
public:
    char findTheDifference(string s, string t) {
        char result = 0;
        for (auto c : s) {
            result -= c; 
        }
        for (auto c : t) {
            result += c;
        }
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: string, fun
 * 
 * */
