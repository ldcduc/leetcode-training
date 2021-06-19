/* Problem url: https://leetcode.com/problems/search-in-rotated-sorted-array
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, pivot = -1;
        // Find the pivot
        while (l <= r) {
            int m = (l + r) >> 1;
            if (m + 1 < nums.size() && nums[m + 1] < nums[m]) {
                pivot = m;
                break;
            } else if (nums[m] <= nums.back()) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        l = pivot + 1, r = pivot + nums.size();
        while (l <= r) {
            int m = (l + r) >> 1;
            int val = nums[m % nums.size()];
            if (val == target) {
                return m % nums.size();
            } else if (val < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return -1; 
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: binary search
 * 
 * */
