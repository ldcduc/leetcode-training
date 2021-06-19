/* Problem url: https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum
 * Code by: ldcduc
 * */
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int mod = (int) 1e9 + 7;
        int long even = 1, odd = 0, result = 0, sum = 0;
        for (auto a : arr) {
            sum = (sum + a) % 2;
            if (sum) {
                result = (result + even) % mod;
                odd = (odd + 1) % mod;
            } else {
                result = (result + odd) % mod;
                even = (even + 1) % mod;
            }
        }
        return result;
    }
};

/*
 * Comment by ldcduc
 * Suggested tags: math, careful
 * 
 * */

