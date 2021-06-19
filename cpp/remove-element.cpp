/* Problem url: https://leetcode.com/problems/remove-element
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        for (int i = n - 1; i >= 0; -- i) {
            if (nums[i] == val) {
                for (int j = i + 1; j < n; ++ j) {
                    swap(nums[j - 1], nums[j]);
                }
                -- n;
            }
        }        
        return n;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: array
 * 
 * */
