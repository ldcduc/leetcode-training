/* Problem url: https://leetcode.com/problems/count-of-smaller-numbers-after-self
 * Code by: ldcduc
 * */
class Solution {
public:
    vector<int> BIT;

    Solution() {
        BIT.resize(20002, 0);
    }
    void update(int val) {
        while (val <= 20001) {
            ++BIT[val];
            val += val & -val;
        }
    }
    int count(int val) {
        int result = 0;
        while (val) {
            result += BIT[val];
            val -= val & -val;
        }
        return result;
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> counts(nums.size());
        for (int i = nums.size() - 1; i >= 0; -- i) {
            nums[i] += 10001;
            counts[i] = count(nums[i] - 1);
            update(nums[i]);
        }
        return counts;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: binary indexed tree
 * 
 * */

