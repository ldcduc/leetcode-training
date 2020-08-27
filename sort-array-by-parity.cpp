/* Problem url: https://leetcode.com/problems/sort-array-by-parity
 * Code by: ldcduc
 * */
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> result;
        for (auto a : A) {
            if ((a - 1) % 2) {
                result.push_back(a);
            }
        }
        for (auto a : A) {
            if (a % 2) {
                result.push_back(a);
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

