/* Problem url: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array
 * Code by: ldcduc
 * */
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int r = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        vector<int> result;
        if (l == nums.size() || nums[l] != target) {
            result.push_back(-1);
            result.push_back(-1);
        } else {
            result.push_back(l);
            result.push_back(r - 1);
        }
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: binary search
 * 
 * */

