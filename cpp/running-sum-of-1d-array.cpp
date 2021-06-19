/* Problem url: https://leetcode.com/problems/running-sum-of-1d-array
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> result(nums.size());
        for (int i = 0; i < nums.size(); ++ i) {
            result[i] = i == 0 ? nums[i] : result[i - 1] + nums[i];
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: dynamic programming
 * 
 * */
