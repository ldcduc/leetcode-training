/* Problem url: https://leetcode.com/problems/search-insert-position
 * Code by: ldcduc
 * */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (nums[m] == target) {
                return m;
            } else {
                if (nums[m] < target && (m == nums.size() - 1 || nums[m + 1] > target)) {
                    return m + 1;
                } else if (nums[m] < target) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }
        return 0;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: binary search
 * 
 * */

