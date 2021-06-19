/* Problem url: https://leetcode.com/problems/subarray-sum-equals-k
 * Code by: ldcduc
 * */
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int result = 0, sum = 0;
        ++m[0];
        for (auto num : nums) {
            sum += num;
            if (m.count(sum - k)) {
                result += m[sum - k];
            }
            ++m[sum];
        }
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: 
 * 
 * */

