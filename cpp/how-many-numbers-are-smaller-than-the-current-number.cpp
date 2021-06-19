/* Problem url: https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number
 * Code by: ldcduc
 * */
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> cnt(101, 0);
        for (auto num : nums) {
            ++cnt[num];
        }
        for (int i = 1; i <= 100; ++ i) {
            cnt[i] += cnt[i - 1];
        }
        vector<int> result(nums.size());
        for (int i = 0; i < nums.size(); ++ i) {
            result[i] = nums[i] > 0 ? cnt[nums[i] - 1] : 0;
        }
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: easy
 * 
 * */
