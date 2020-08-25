/* Problem url: https://leetcode.com/problems/subarray-product-less-than-k
 * Code by: ldcduc
 * */
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int result = 0, count_ = 0, from_;
        long long product = 1;
        nums.push_back(k);
        for (int i = 0; i < nums.size(); ++ i) {
            while (from_ < i && product * nums[i] >= k) {
                result += count_;
                --count_;
                product /= nums[from_];
                ++from_;
            }
            if (product * nums[i] < k) {
                product *= nums[i];
                ++count_;
                from_ = min(from_, i);
            }
        }
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: fun
 * 
 * */

