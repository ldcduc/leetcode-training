/* Problem url: https://leetcode.com/problems/contains-duplicate-iii
 * Code by: ldcduc
 * */
class Solution {
public:
    vector<int> BIT;
    int maxVal;

    void update(int val, int change) {
        while (val <= maxVal) {
            BIT[val] += change;
            val += val & -val;
        }
    }
    int count(int val) {
        val = min(val, maxVal);
        int result = 0;
        while (val > 0) {
            result += BIT[val];
            val -= val & -val;
        }
        return result;
    }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        vector<pair<int, int> > arr;
        for (int i = 0; i < nums.size(); ++ i) {
            arr.push_back(make_pair(nums[i], i + 1));
        }
        sort(arr.begin(), arr.end());

        BIT.resize(nums.size() + 1);
        maxVal = nums.size();

        int left = 0, right;
        for (right = 0; right < nums.size(); ++ right) {
            while (left < right && 1ll * arr[right].first - arr[left].first > t) {
                update(arr[left].second, -1);
                ++left;
            }
            if (count(arr[right].second + k) - count(arr[right].second - k - 1)) {
                return true;
            }
            update(arr[right].second, 1);
        }
        return false;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: binary indexed tree
 * 
 * */

