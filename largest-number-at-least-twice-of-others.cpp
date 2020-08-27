/* Problem url: https://leetcode.com/problems/largest-number-at-least-twice-of-others
 * Code by: ldcduc
 * */
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int result = nums.size() > 0 ? 0 : -1;
        for (int i = 0; i < nums.size(); ++ i) {
            if (nums[i] > nums[result]) {
                result = i;
            }
        }
        for (int i = 0; i < nums.size(); ++ i) {
            if (i != result && nums[i] * 2 > nums[result]) {
                return -1;
            }
        }
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: 
 * 
 * */

