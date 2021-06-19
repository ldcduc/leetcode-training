/* Problem url: https://leetcode.com/problems/total-hamming-distance
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int result = 0, n = nums.size();
        for (int i = 0; i < 32; ++ i) {
            int cntOne = 0;
            for (auto num : nums) {
                cntOne += (num >> i) & 1;
            }
            result += cntOne * (n - cntOne);
        } 
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: bit manipulation
 * 
 * */
