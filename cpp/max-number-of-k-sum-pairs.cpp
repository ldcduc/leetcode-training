/* Problem url: https://leetcode.com/problems/max-number-of-k-sum-pairs
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> M;
        for (auto num : nums) {
            if (M.count(num) == 0) {
                M[num] = 1; 
            } else {
                ++ M[num];
            } 
        }    
        int result = 0;
        for (auto num : nums) {
            if (k - num == num) {
                result += M[num] / 2;
                M[num] = 0;
            } else if (M.count(k - num) > 0) {
                result += min(M[num], M[k - num]);
                M[num] = 0;
                M[k - num] = 0;
            }
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
