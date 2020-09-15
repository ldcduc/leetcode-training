/* Problem url: https://leetcode.com/problems/container-with-most-water
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int maxArea(vector<int>& height) {
        vector<pair<int, int>> tmp;
        for (int i = 0; i < height.size(); ++ i) {
            tmp.push_back(make_pair(height[i], i));
        }    
        sort(tmp.rbegin(), tmp.rend());
        priority_queue<int> minQ, maxQ;
        int result = 0;
        for (int i = 0; i < tmp.size(); ++ i) {
            if (i) {
                result = max(result, tmp[i].first * (tmp[i].second + minQ.top())); // - (-minQ.top())
                result = max(result, tmp[i].first * (maxQ.top() - tmp[i].second));
            }        
            minQ.push(-tmp[i].second);
            maxQ.push(tmp[i].second);
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: sorting, fun
 * 
 * */
