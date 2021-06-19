/* Problem url: https://leetcode.com/problems/longest-harmonious-subsequence
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> M;
        for (int i = 0; i < nums.size(); ++ i) {
            ++ M[nums[i]];
        }
        int result = 0;
        for (auto item : M) {
            if (M.count(item.first + 1) > 0) {
                result = max(result, item.second + M[item.first + 1]);
            }
        }
        return result; 
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: hash map, sorting
 * 
 * */
