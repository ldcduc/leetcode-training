/* Problem url: https://leetcode.com/problems/maximum-subarray
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0], sum = 0;
        for (auto num : nums) {
            sum += num;
            result = max(result, sum);
            sum = max(sum, 0);
        } 
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: array, Kadane algorithm
 * 
 * */
