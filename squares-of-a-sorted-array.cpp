/* Problem url: https://leetcode.com/problems/squares-of-a-sorted-array
 * Code by: ldcduc
 * */
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> result;
        for (auto a : A) {
            result.push_back(a * a);
        } 
        sort(result.begin(), result.end());
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: 
 * 
 * */

