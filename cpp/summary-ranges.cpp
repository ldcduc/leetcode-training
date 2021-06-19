/* Problem url: https://leetcode.com/problems/summary-ranges
 * Code by: ldcduc
 * */
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if (nums.size()) {
            int left_end = nums[0];
            for (int i = 1; i < nums.size(); ++ i) {
                if (nums[i] != nums[i - 1] + 1) {
                    string s = to_string(left_end);
                    if (nums[i - 1] != left_end) {
                        s += "->" + to_string(nums[i - 1]);
                    }
                    result.push_back(s);
                    left_end = nums[i];
                }
            }
            string s = to_string(left_end);
            if (nums.back() != left_end) {
                s += "->" + to_string(nums.back());
            }
            result.push_back(s);
        }
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: string
 * 
 * */

