/* Problem url: https://leetcode.com/problems/height-checker
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> tmp(heights);
        int result = 0;
        sort(tmp.begin(), tmp.end());
        for (int i = 0; i < tmp.size(); ++ i) {
            result += heights[i] != tmp[i];
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: array
 * 
 * */
