/* Problem url: https://leetcode.com/problems/insert-interval
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    bool overlap(pair<int, int> x, pair<int, int> y) {
        return !(x.second < y.first || y.second < x.first);
    }
    pair<int, int> merge(pair<int, int> x, pair<int, int> y) {
        return make_pair(min(x.first, y.first), max(x.second, y.second));
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        set<pair<int, int>> S;
        for (auto interval : intervals) {
            S.insert(make_pair(interval[0], interval[1]));
        }
        pair<int, int> interval = make_pair(newInterval[0], newInterval[1]);
        set<pair<int, int>>::iterator it;
        it = S.lower_bound(interval);
        while (!S.empty()) {
            it = S.lower_bound(interval);
            if (it != S.end() && overlap(*it, interval)) {
                interval = merge(*it, interval);
                S.erase(it);
            } else {
                break;
            }
        }
        while (!S.empty()) {
            it = S.lower_bound(interval);
            if (it != S.begin()) {
                -- it;
                if (overlap(*it, interval)) {
                    interval = merge(*it, interval);
                    S.erase(it);
                    continue;
                }
            }
            break;
        }
        S.insert(interval);
        for (auto item : S) {
            result.push_back({item.first, item.second});
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: std::set
 * 
 * */
