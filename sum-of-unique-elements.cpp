/* Problem url: https://leetcode.com/problems/sum-of-unique-elements
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        vector<int> cnt(101, 0);
        for (int i = 0; i < nums.size(); ++ i) {
            ++ cnt[nums[i]];
        }
        int result = 0;
        for (int i = 0; i < nums.size(); ++ i) {
            if (cnt[nums[i]] == 1) {
                result += nums[i];
            }
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: array
 * 
 * */
