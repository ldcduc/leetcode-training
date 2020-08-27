/* Problem url: https://leetcode.com/problems/contains-duplicate-ii
 * Code by: ldcduc
 * */
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        vector<pair<int, int> > arr;
        for (int i = 0; i < nums.size(); ++ i) {
            arr.push_back(make_pair(nums[i], i));
        }
        sort(arr.begin(), arr.end());
        if (nums.size() > 1) {
            for (int i = 1; i < nums.size(); ++i) {
                if (arr[i].first == arr[i - 1].first && arr[i].second - arr[i - 1].second <= k) {
                    return true;
                }
            }
        }
        return false;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: 
 * 
 * */

