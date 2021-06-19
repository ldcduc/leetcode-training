/* Problem url: https://leetcode.com/problems/merge-intervals
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &x, const vector<int> &y) {
            if (x[0] == y[0]) {
                return x[1] > y[1];
            }
            return x[0] < y[0];
        });
        for (auto interval : intervals) {
            if (!result.empty() && interval[0] <= result.back()[1]) {
                interval[0] = result.back()[0];
                interval[1] = max(interval[1], result.back()[1]);
                result.pop_back();
            }
            result.push_back(interval);
        }
        return result;
    }
};
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        stack<vector<int>> s;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &x, const vector<int> &y) {
            if (x[0] == y[0]) {
                return x[1] > y[1];
            }  
            return x[0] < y[0];
        });
        for (auto interval : intervals) {
            if (!s.empty() && interval[0] <= s.top()[1]) {
                interval[0] = s.top()[0];
                interval[1] = max(interval[1], s.top()[1]);
                s.pop();
                //s.push(interval);
            } /* else {
                s.push(interval);
            } */
            s.push(interval);    
        }
        vector<vector<int>> result;
        while (!s.empty()) {
            result.push_back(s.top());
            s.pop();
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: stack
 * 
 * */
