/* Problem url: https://leetcode.com/problems/ugly-number-ii
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long long> nums(1, 1);
        int size = 1, i = 0, j = 0, k = 0;
        while (size < n) {
            nums.push_back(min(min(nums[i] * 2, nums[j] * 3), nums[k] * 5));
            ++ size;
            if (nums[i] * 2 == nums.back()) {
                ++ i;
            }
            if (nums[j] * 3 == nums.back()) {
                ++ j;
            }
            if (nums[k] * 5 == nums.back()) {
                ++ k;
            }
        }
        return nums.back();
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: dynamic programming
 * 
 * */
