/* Problem url: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array
 * Code by: ldcduc
 * */
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();
        for (auto num : nums) {
            nums[abs(num) - 1] = -abs(nums[abs(num) - 1]);
        }
        for (int i = 0; i < n; ++ i) {
            if (nums[i] > 0) {
                result.push_back(i + 1);
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

