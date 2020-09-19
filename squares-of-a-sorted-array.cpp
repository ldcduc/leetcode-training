/* Problem url: https://leetcode.com/problems/squares-of-a-sorted-array
 * Code by: ldcduc
 * */
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> result;
        int p1 = -1, p2 = -1;
        for (int i = 1; i < A.size(); ++ i) {
            if ((A[i - 1] < 0) ^ (A[i] < 0)) {
                p1 = i - 1;
                p2 = i;
            }
        }
        if (p1 == -1) {
            if (A[0] >= 0) {
                for (int i = 0; i < A.size(); ++ i) {
                    result.push_back(A[i] * A[i]);
                }
            } else {
                for (int i = A.size() - 1; i >= 0; -- i) {
                    result.push_back(A[i] * A[i]);
                }
            }
        } else {
            while (0 <= p1 && p2 < A.size()) {
                if (-A[p1] < A[p2]) {
                    result.push_back(A[p1] * A[p1]);
                    -- p1;
                } else {
                    result.push_back(A[p2] * A[p2]);
                    ++ p2;
                }
            }
            while (p1 >= 0) {
                result.push_back(A[p1] * A[p1]);
                -- p1;
            }
            while (p2 < A.size()) {
                result.push_back(A[p2] * A[p2]);
                ++ p2;
            }
        }
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: 
 * 
 * */

