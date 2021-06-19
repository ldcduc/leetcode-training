/* Problem url: https://leetcode.com/problems/k-closest-points-to-origin
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> Q;
        vector<vector<int>> result;
        for (auto point : points) {
            pair<int, pair<int, int>> item;
            item.first = point[0] * point[0] + point[1] * point[1];
            item.second = make_pair(point[0], point[1]);
            Q.push(item);
        }  
        for (int i = 0; i < K; ++ i) {
            result.push_back({Q.top().second.first, Q.top().second.second});    
            Q.pop();
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: heap
 * 
 * */
