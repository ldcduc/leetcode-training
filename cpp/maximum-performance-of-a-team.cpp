/* Problem url: https://leetcode.com/problems/maximum-performance-of-a-team
 * Code by: ldcduc
 * */
bool compare(pair<int, int> x, pair<int, int> y) {
    return x.first > y.first;
}
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        long long result = 0;
        vector<pair<int, int> > effs;
        for (int i = 0; i < n; ++ i) {
            effs.push_back(make_pair(efficiency[i], i));
        }
        sort(effs.begin(), effs.end(), compare);
        priority_queue<pair<int, int> > Q;
        long long sumSpeed = 0;
        for (int i = 0; i < n; ++ i) {
            if (Q.size() == k) {
                sumSpeed += Q.top().first;
                Q.pop();
            }
            Q.push(make_pair(-speed[effs[i].second], effs[i].second));
            sumSpeed += speed[effs[i].second];
            long long tmp = 1ll * sumSpeed * effs[i].first;
            if (tmp > result) {
                result = tmp;
            }
        }
        return result % ((int) 1e9 + 7);
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: sorting
 * 
 * */

