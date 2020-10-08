/* Problem url: https://leetcode.com/problems/number-of-good-pairs
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int result = 0;
        vector<int> count(101, 0);
        for (auto num : nums) {
            ++ count[num];
        }
        for (auto val : count) {
            result += val * (val - 1) / 2;    
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
