/* Problem url: https://leetcode.com/problems/sort-colors
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> cnt(3, 0);
        for (int i = 0; i < nums.size(); ++ i) {
            ++ cnt[nums[i]];
        }
        for (int i = 0; i < nums.size(); ++ i) {
            if (cnt[0]) {
                nums[i] = 0;
                -- cnt[0];
            } else if (cnt[1]) {
                nums[i] = 1;
                -- cnt[1];
            } else {
                nums[i] = 2;
                -- cnt[2];
            }
        }
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: sorting, counting
 * 
 * */
