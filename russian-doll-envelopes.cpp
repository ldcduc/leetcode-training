/* Problem url: https://leetcode.com/problems/russian-doll-envelopes
 * Code by: ldcduc
 * */
bool compare(vector<int> x, vector<int> y) {
    if (x[1] == y[1]) {
        return x[0] > y[0];
    }
    return x[1] < y[1];
}
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), compare);
        int maxLIS = 0;
        vector<int> pos(1);
        for (int i = 0; i < envelopes.size(); ++ i) {
            int l = 1, r = maxLIS, tmp = 0;
            while (l <= r) {
                int m = (l + r) >> 1;
                if (envelopes[pos[m]][0] < envelopes[i][0]) {
                    tmp = m;
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            if (tmp + 1 > maxLIS) {
                maxLIS = tmp + 1;
                pos.push_back(i);
            } else if (envelopes[i][0] < envelopes[pos[tmp + 1]][0]) {
                pos[tmp + 1] = i;
            }
        }
        return maxLIS;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: LIS
 * 
 * */

