/* Problem url: https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int result = 0;
        unordered_map<int, int> M;
        for (auto num : arr) {
            int length;
            if (M.count(num - difference)) {
                length = M[num - difference] + 1;    
            } else {
                length = 1; 
            }
            if (M.count(num)) {
                int tmp = M[num];
                tmp = max(tmp, length);
                M[num] = tmp;
            } else {
                M[num] = length;
            }
            result = max(result, length);
        }
        return result; 
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: hash map
 * 
 * */
