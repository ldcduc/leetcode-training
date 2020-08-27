/* Problem url: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array
 * Code by: ldcduc
 * */
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        for (int i = 0; i < nums.size(); ++ i) {
            if (nums[i] == target) {
                if (i == 0 || nums[i] != nums[i - 1]) {
                    result.push_back(i);
                }
                if (i == nums.size() - 1 || nums[i] != nums[i + 1]) {
                    result.push_back(i);
                }
            }
        }

        if (result.empty()) {
            result.push_back(-1);
            result.push_back(-1);
        }
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: 
 * 
 * */

