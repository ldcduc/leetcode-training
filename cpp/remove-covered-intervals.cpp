/* Problem url: https://leetcode.com/problems/remove-covered-intervals
 * Code by: ldcduc
 * */
/* Begin of Solution */
bool compare(vector<int>& first, vector<int>& second) {
    if (first[0] == second[0]) {
        return first[1] > second[1];    
    } 
    return first[0] < second[0];
}
class Solution {
public:
    bool isCovered(vector<int>& interval1, vector<int>& interval2) {
        return interval2[0] <= interval1[0] && interval1[1] <= interval2[1];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end(), compare);
        for (auto interval : intervals) {
            if (result.empty()) {
                result.push_back(interval);
            } else {
                if (!isCovered(interval, result.back())) {
                    result.push_back(interval);        
                }
            }
        }
        return result.size();
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: sorting
 * 
 * */
