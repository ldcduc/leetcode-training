/* Problem url: https://leetcode.com/problems/move-zeroes
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; ++ i) {
            bool positive = false;
            if (nums[i] == 0) {
                for (int j = i + 1; j < nums.size(); ++ j) {
                    positive |= nums[j] > 0;
                    swap(nums[j - 1], nums[j]);
                }
            }
            if (nums[i] == 0 && positive) {
                -- i;
            }
        }    
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: array, in-place operation
 * 
 * */
