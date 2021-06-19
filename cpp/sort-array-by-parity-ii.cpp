/* Problem url: https://leetcode.com/problems/sort-array-by-parity-ii
 * Code by: ldcduc
 * */
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> result(A.size());
        int odd = 1, even;
        for (even = 0; even < A.size() && odd < A.size(); even += 2) {
            while (A[odd] % 2) {
                result[odd] = A[odd];
                odd += 2;
                if (odd >= A.size()) {
                    break;
                }
            }
            if (A[even] % 2) {
                result[odd] = A[even];
                result[even] = A[odd];
                swap(A[odd], A[even]);
                odd += 2;
            } else {
                result[even] = A[even];
            }
        }
        for (; odd < A.size(); odd += 2) {
            result[odd] = A[odd];
        }
        for (; even < A.size(); even += 2) {
            result[even] = A[even];
        }
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: math, careful
 * 
 * */

