/* Problem url: https://leetcode.com/problems/teemo-attacking
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int result = 0, poisonedUntil = timeSeries.size() ? timeSeries[0] : 0;
        for (auto time : timeSeries) {
            result += duration - max(poisonedUntil - time, 0);
            poisonedUntil = time + duration;
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: sorting
 * 
 * */
