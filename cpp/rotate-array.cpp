/* Problem url: https://leetcode.com/problems/rotate-array
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        for (; k; -- k) {
            int tmp = nums[n - 1];
            for (int i = n - 1; i > 0; -- i) {
                nums[i] = nums[i - 1];    
            }
            nums[0] = tmp;
        }
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: matrix
 * 
 * */
