/* Problem url: https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to
 * Code by: ldcduc
 * */
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int> > result;
        vector<pair<int, int> > tmp;
        for (int i = 0; i < groupSizes.size(); ++ i) {
            tmp.push_back(make_pair(groupSizes[i], i));
        }
        sort(tmp.begin(), tmp.end());

        if (!tmp.empty()) {
            int cnt = 0;
            vector<int> group;
            for (int i = 0; i < tmp.size(); ++ i) {
                ++cnt;
                group.push_back(tmp[i].second);
                if (cnt == tmp[i].first) {
                    result.push_back(group);
                    group.clear();
                    cnt = 0;
                }
            }
        }

        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: sort
 * 
 * */

