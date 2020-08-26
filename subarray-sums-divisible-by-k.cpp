/* Problem url: https://leetcode.com/problems/subarray-sums-divisible-by-k
 * Code by: ldcduc
 * */
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        vector<int> cnt_(K, 0);
        cnt_[0] = 1;
        int sum = 0, result = 0;
        for (auto a : A) {
            sum = (sum + a + K * K) % K;
            result += cnt_[sum];
            ++cnt_[sum];
        }
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: math, careful
 * 
 * */

