/* Problem url: https://leetcode.com/problems/first-missing-positive/
 * Code by: ldcduc
 * */
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        nums.push_back(0);
        int n = nums.size();
        for (int i=0; i<n; ++i)
            if (nums[i] <= 0) nums[i] = (1<<30);
        for (int i=0; i<n; ++i) {
            int value = abs(nums[i]);
            if (value > 0 && value < n)
                nums[value-1] = -abs(nums[value-1]);
        }
        for (int i=0; i<n; ++i) {
            if (nums[i] >= 0) return i+1;
        }
        return 0; // This line will be never reached
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: array
 *
 * */
