/* Problem url: https://leetcode.com/problems/find-peak-element
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;    
        while (l < r) {
            int m = (l + r) >> 1;
            if (nums[m] < nums[m + 1]) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: binary search
 * 
 * */
