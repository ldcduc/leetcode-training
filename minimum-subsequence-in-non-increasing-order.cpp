/* Problem url: https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order
 * Code by: ldcduc
 * */
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        vector<int> result;
        sort(nums.rbegin(), nums.rend());
        int sum = 0, chosenSum = 0;
        for (auto num : nums) {
            sum += num;
        }
        for (auto num : nums) {
            chosenSum += num;
            sum -= num;
            result.push_back(num);
            if (chosenSum > sum) {
                return result;
            }
        }
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: easy
 * 
 * */

