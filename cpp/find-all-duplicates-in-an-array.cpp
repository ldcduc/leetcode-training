/* Problem url: https://leetcode.com/problems/find-all-duplicates-in-an-array/
 * Code by: ldcduc
 * */
class Solution {
public:
    int abs(int x) {
        return (x < 0) ? -x : x;
    }
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();
        for (int i=0; i<n; ++i) {
            if (nums[abs(nums[i]) - 1] < 0) {
                result.push_back(abs(nums[i]));
            }
            nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
        }
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: implementation, trick
 * 
 * */

