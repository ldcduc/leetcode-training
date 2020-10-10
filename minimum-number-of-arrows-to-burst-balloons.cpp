/* Problem url: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons
 * Code by: ldcduc
 * */
/* Begin of Solution */
bool compare(vector<int>& x, vector<int>& y) {
    return x[0] == y[0] ? x[1] > y[1] : x[0] < y[0];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), compare);    
        int result = 0;
        if (!points.empty()) {
            int start = points[0][0], end = points[0][1];
            result = 1;
            for (auto point : points) {
                if (point[1] < start || end < point[0]) { // not overlapping
                    ++ result;    
                    start = point[0];
                    end = point[1];
                } else {
                    start = max(start, point[0]);
                    end = min(end, point[1]);
                }
            }
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
