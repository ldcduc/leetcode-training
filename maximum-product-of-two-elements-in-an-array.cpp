/* Problem url: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int result = 0;
        for (int i = 1; i < nums.size(); ++ i) {
            result = max(result, (nums[i - 1] - 1) * (nums[i] - 1));
        } 
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: math
 * 
 * */
