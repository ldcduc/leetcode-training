/* Problem url: https://leetcode.com/problems/get-maximum-in-generated-array
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int getMaximumGenerated(int n) {
        int result = n > 0;
        if (n > 0) {
            vector<int> nums(n + 1, 0);
            nums[1] = 1;
            for (int i = 2; i <= n; ++ i) {
                nums[i] = nums[i / 2] + (i % 2) * nums[(i / 2) + 1]        ;
                result = max(result, nums[i]);
            } 
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
