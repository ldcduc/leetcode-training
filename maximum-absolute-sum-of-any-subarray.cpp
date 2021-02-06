/* Problem url: https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        vector<int> s(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++ i) {
            s[i + 1] = s[i] + nums[i];
        }
        int maxx = s[0], minn = s[0], result = 0;
        for (int i = 1; i <= nums.size(); ++ i) {
            result = max(result, abs(s[i] - maxx));
            result = max(result, abs(s[i] - minn));
            maxx = max(maxx, s[i]);
            minn = min(minn, s[i]);
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
