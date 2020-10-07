/* Problem url: https://leetcode.com/problems/shuffle-the-array
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> result(2 * n);
        for (int i = 0; i < n; ++ i) {
            result[i * 2] = nums[i];
            result[i * 2 + 1] = nums[i + n];
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
