/* Problem url: https://leetcode.com/problems/sort-colors
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        for (int i = 0; i <= end; ) {
            if (nums[i] == 0) {
                if (i > start) {
                    swap(nums[i], nums[start ++]);
                } else {
                    ++ i;
                }
            } else if (nums[i] == 1) {
                ++ i;
            } else {
                if (i < end) {
                    swap(nums[i], nums[end --]);
                } else {
                    ++ i;
                }
            }
        }
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: sorting, inplace sort
 * 
 * */
