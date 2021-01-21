/* Problem url: https://leetcode.com/problems/sort-array-by-increasing-frequency
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<pair<int, int>> f(201, {0, 0});
        for (int i = 0; i < nums.size(); ++ i) {
            ++ f[nums[i] - -100].second;
            f[nums[i] - -100].first = nums[i];
        }
        sort(f.begin(), f.end(), [](pair<int, int> x, pair<int, int> y) {
            if (x.second == y.second) {
                return x.first > y.first;
            }
            return x.second < y.second;
        });
        vector<int> result;
        for (auto item : f) {
            for (int i = 0; i < item.second; ++ i) {
                result.push_back(item.first);    
            }
        } 
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: sorting, array
 * 
 * */
