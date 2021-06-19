/* Problem url: https://leetcode.com/problems/two-sum
 * Code by: ldcduc
 * */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++ i) {
            if (m.count(target - nums[i]) > 0) {
                result.push_back(m[target - nums[i]]);
                result.push_back(i);
            }
            m[nums[i]] = i;
        }
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: hash map
 * 
 * */
