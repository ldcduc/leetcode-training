/* Problem url: https://leetcode.com/problems/non-overlapping-intervals
 * Code by: ldcduc
 * */
bool compare(vector<int> first, vector<int> second) {
    return first[1] < second[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        int res = 0, lastEnd;
        for (auto interval : intervals) {
            cout << interval[0] << ' ' << interval[1] << endl;
            if (res > 0) {
                if (interval[0] >= lastEnd) {
                    lastEnd = interval[1];
                    ++res;
                }
            } else {
                res = 1;
                lastEnd = interval[1];
            }
        }
        return intervals.size() - res;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: sorting, greedy
 * 
 * */

