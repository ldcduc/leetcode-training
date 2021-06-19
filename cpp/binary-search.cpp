/* Problem url: https://leetcode.com/problems/binary-search
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int result = -1;
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (nums[m] == target) {
                result = m;
                break;
            } else if (nums[m] < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: binary search
 * 
 * */
