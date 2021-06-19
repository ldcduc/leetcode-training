/* Problem url: https://leetcode.com/problems/add-to-array-form-of-integer
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int n = A.size(), remainder = 0;
        vector<int> result(n);
        for (int i = n - 1; i >= 0; -- i) {
            remainder += A[i] + K % 10;
            result[i] = remainder % 10;
            K /= 10;
            remainder /= 10;
        }    
        remainder += K;
        while (remainder > 0) {
            result.push_back(0);
            for (int i = result.size() - 1; i > 0; -- i) {
                result[i] = result[i - 1];
            }
            result[0] = remainder % 10;
            remainder /= 10;
        } 
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: array
 * 
 * */
