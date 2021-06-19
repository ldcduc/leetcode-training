/* Problem url: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int findMin(vector<int>& nums) {
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
        return nums[(pivot + 1) % nums.size()];
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: binary search
 * 
 * */
