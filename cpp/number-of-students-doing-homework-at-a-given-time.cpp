/* Problem url: https://leetcode.com/problems/number-of-students-doing-homework-at-a-given-time
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int res = 0;
        for (auto num : startTime) {
            res += (num <= queryTime);
        } 
        for (auto num : endTime) {
            res -= (num < queryTime);
        }
        return res;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: fun
 * 
 * */
