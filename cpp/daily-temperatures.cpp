/* Problem url: https://leetcode.com/problems/daily-temperatures
 * Code by: ldcduc
 * */
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int size_ = T.size();
        vector<int> result(size_);
        stack<int> s;
        for (int i = 0; i < size_; ++ i) {
            while (!s.empty() && T[i] > T[s.top()]) {
                result[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        while (!s.empty()) {
            result[s.top()] = 0;
            s.pop();
        }
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: fun
 * 
 * */
