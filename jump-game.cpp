/* Problem url: https://leetcode.com/problems/jump-game
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> reached(n, false);
        vector<int> countTrue(n + 1, 0);
        reached[n - 1] = true; 
        countTrue[n - 1] = 1; 
        for (int i = n - 2; i >= 0; -- i) {
            bool canReach = (countTrue[i + 1] - countTrue[min(i + nums[i], n - 1) + 1]) > 0;
            reached[i] = canReach;
            countTrue[i] = countTrue[i + 1] + canReach;  
        } 
        return reached[0];
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: array, accumulative sum
 * 
 * */
