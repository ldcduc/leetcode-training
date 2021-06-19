/* Problem url: https://leetcode.com/problems/sum-of-even-numbers-after-queries
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> result;
        int sum = 0;
        for (auto a : A) {
            sum += (a % 2 == 0) * a;
        }
        for (auto query : queries) {
            if (A[query[1]] % 2 == 0) {
                if ((A[query[1]] + query[0]) % 2) {
                    sum -= A[query[1]];
                } else {
                    sum += query[0];
                }
            } else {
                sum += (query[0] % 2 != 0) * (A[query[1]] + query[0]);
            }
            A[query[1]] += query[0];
            result.push_back(sum);
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: implementation
 * 
 * */
