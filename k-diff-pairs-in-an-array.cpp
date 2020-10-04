/* Problem url: https://leetcode.com/problems/k-diff-pairs-in-an-array
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int result = 0;
        unordered_map<int, int> M;
        for (auto num : nums) {
            ++ M[num];
        }
        for (auto num : nums) {
            if (M.count(num)) {
                if (k != 0) {
                    result += M.count(num - k) > 0;
                    result += M.count(num + k) > 0;
                } else {
                    result += M[num] > 1;
                }
                M.erase(num);
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
