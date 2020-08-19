/* Problem url: https://leetcode.com/problems/single-number-ii
 * Code by: ldcduc
 * */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bitsCnt(32, 0);
        for (auto num : nums) {
            for (int i = 0; i < 32; ++ i) {
                bitsCnt[i] += (num >> i) & 1;
            }
        }
        long long result = 0;
        for (int i = 0; i < 32; ++ i) {
            if (bitsCnt[i] % 3) {
                result += 1ll << i;
            }
        }
        return (int) result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: math, fun
 * 
 * */
