/* Problem url: https://leetcode.com/problems/maximum-sum-circular-subarray
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    void optimize(int &result, int sum, int &optimized) {
        if (!optimized || sum > result) {
            result = sum;
            optimized = true;
        }
    }
    int maxSubarraySumCircular(vector<int>& A) {
        int result, optimized = false, sum = 0; 
        for (auto a : A) {
            sum += a;
            optimize(result, sum, optimized);
            if (sum < 0) {
                sum = 0;
            }
        }
        // max prefix sum, max suffix sum
        vector<int> prefix(A.size()), suffix(A.size()); 
        prefix[0] = A[0];
        suffix[A.size() - 1] = A.back();
        // Calculate sum
        for (int i = 1; i < A.size(); ++ i) {
            prefix[i] = prefix[i - 1] + A[i]; 
            suffix[A.size() - 1 - i] = suffix[A.size() - i] + A[A.size() - 1 - i];
        }
        // Calculate max sum
        for (int i = 1; i <  A.size(); ++ i) {
            prefix[i] = max(prefix[i - 1], prefix[i]);
            suffix[A.size() - 1 - i] = max(suffix[A.size() - 1 - i], suffix[A.size() - i]);
        }
        for (int i = 1; i < A.size(); ++ i) {
            int remain = A.size() - i;
            optimize(result, suffix[A.size() - i] + prefix[remain - 1], optimized);
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: accumulated sum
 * 
 * */
