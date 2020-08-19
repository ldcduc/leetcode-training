/* Problem url: https://leetcode.com/problems/missing-number
 * Code by: ldcduc
 * */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();
        for (auto num : nums) {
            sum += num;
        }
        return 1ll*n*(n+1)/2 - sum;      
    }
};
/*
 * Comment by ldcduc
 * Suggested tags:
 * 
 * */
