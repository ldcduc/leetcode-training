/* Problem url: https://leetcode.com/problems/next-permutation
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int noPermutation = true;
        for (int i = nums.size() - 1 - 1; i >= 0; -- i) {
            if (nums[i] < nums[i + 1]) {
                noPermutation = false;
                int k = nums.size() - 1;
                while (nums[k] <= nums[i]) {
                    -- k;
                }
                swap(nums[i], nums[k]);
                int l = i + 1, r = nums.size() - 1;
                while (l < r) {
                    swap(nums[l], nums[r]);
                    ++ l;
                    -- r;
                }
                break;
            }            
        }    
        if (noPermutation) {
            sort(nums.begin(), nums.end());
        }
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: array
 * 
 * */
