/* Problem url: https://leetcode.com/problems/find-pivot-index
 * Code by: ldcduc
 * */
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> sums(nums.size() + 1);
        sums[0] = 0;
        for (int i = 0; i < n; ++ i) {
            sums[i + 1] = sums[i] + nums[i];
        }
        for (int i = 1; i <= n; ++ i) {
            if (sums[i - 1] == sums[n] - sums[i]) {
                return i - 1;
            }
        }
        return -1;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: 
 * 
 * */

