/* Problem url: https://leetcode.com/problems/largest-rectangle-in-histogram
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    void maximize(int &a, int b) {
        if (b > a) {
            a = b;
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        int result = 0;
        stack<pair<int, int> > S; // { left_, index }
        for (int i = 0; i < heights.size(); ++ i) {
            int left_ = i;
            while (!S.empty() && heights[S.top().second] > heights[i]) {
                maximize(result, heights[S.top().second] * (i - S.top().first));
                left_ = S.top().first;
                S.pop();
            }
            S.push(make_pair(left_, i));
        }    
        while (!S.empty()) {
            maximize(result, heights[S.top().second] * (heights.size() - S.top().first));
            S.pop();
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
