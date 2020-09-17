/* Problem url: https://leetcode.com/problems/max-consecutive-ones
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int result = 0;
        nums.push_back(0);
        int cnt = 0;
        for (int i = nums.size() - 2; i >= 0; -- i) {
            cnt = (nums[i + 1] == 0 ? 1 : cnt + 1) * nums[i];
            result = max(result, cnt);
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: ad-hoc
 * 
 * */
