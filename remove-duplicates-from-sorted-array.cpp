/* Problem url: https://leetcode.com/problems/remove-duplicates-from-sorted-array
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();    
        for (int i = 1; i < n; ++ i) {
            if (nums[i] == nums[i - 1]) {
                for (int j = i + 1; j < n; ++ j) {
                    swap(nums[j - 1], nums[j]);
                }         
                -- n;    
            }
            if (nums[i] == nums[i - 1]) {
                -- i;
            }
        }
        return n;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: array, in-place operation
 * 
 * */
