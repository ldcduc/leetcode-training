/* Problem url: https://leetcode.com/problems/longest-continuous-increasing-subsequence
 * Code by: ldcduc
 * */
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int result = 0;
        for (int i = 1, score = 1; i < nums.size(); ++i) {
            score = nums[i] > nums[i - 1] ? score + 1 : 1;
            if (score > result) {
                result = score;
            }
        }
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: sequence
 * 
 * */
