/* Problem url: https://leetcode.com/problems/single-number-iii
 * Code by: ldcduc
 * */
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorSum = 0;
        for (auto num : nums) {
            xorSum ^= num;
        }
        xorSum = xorSum & -xorSum;

        int xorSum1 = 0, xorSum2 = 0;
        for (auto num : nums) {
            if (xorSum & num) {
                xorSum1 ^= num;
            } else {
                xorSum2 ^= num;
            }
        }

        vector<int> result;
        result.push_back(xorSum1);
        result.push_back(xorSum2);
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: math, fun
 * 
 * */
