/* Problem url: https://leetcode.com/problems/maximum-average-subarray-i
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0, result = 0;
        for (int i = 0; i < k; ++ i) {
            sum += nums[i];    
        }
        result = sum;
        for (int i = k; i < nums.size(); ++ i) {
            sum -= nums[i - k];
            sum += nums[i];
            if (sum > result) {
                result = sum;
            }
        }
        return result / k;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: array
 * 
 * */
