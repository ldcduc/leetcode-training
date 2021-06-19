/* Problem url: https://leetcode.com/problems/decompress-run-length-encoded-list
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i += 2) {
            for (int j = 0; j < nums[i]; ++ j) {
                result.push_back(nums[i + 1]);
            }
        } 
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: implementation
 * 
 * */
