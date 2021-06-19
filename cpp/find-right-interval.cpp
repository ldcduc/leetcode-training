/* Problem url: https://leetcode.com/problems/find-right-interval/
 * Code by: ldcduc
 * */
bool compare(vector<int> x, vector<int> y) {
    if (x[0] == y[0]) {
        return x[1] < y[1];
    }
    return x[0] < y[0];
}
bool compare2(vector<int> x, vector<int> y) {
    return x[2] < y[2];
}
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        for (int i = 0; i < intervals.size(); ++i) {
            intervals[i].push_back(i);
        }
        sort(intervals.begin(), intervals.end(), compare);

        vector<int> result(intervals.size());

        if(!intervals.empty()) {
            for (int i = 0; i < intervals.size(); ++ i) {
                int l = i + 1, r = intervals.size() - 1, found = -1;
                while (l <= r) {
                    int m = (l + r) >> 1;
                    if (intervals[i][1] <= intervals[m][0]) {
                        found = intervals[m][2];
                        r = m - 1;
                    } else {
                        l = m + 1;
                    }
                }
                result[intervals[i][2]] = found;
            }
        }

        sort(intervals.begin(), intervals.end(), compare2);
        for (int i = 0; i < intervals.size(); ++i) {
            intervals[i].pop_back();
        }
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: sort, binary search
 * 
 * */
