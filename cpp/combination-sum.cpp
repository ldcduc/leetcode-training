/* Problem url: https://leetcode.com/problems/combination-sum
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    void recursion(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& chosen) {
        if (target == 0) {
            result.push_back(chosen);    
        } else {
            for (int i = chosen.empty() ? 0 : chosen.back(); i < candidates.size(); ++ i) {
                if (candidates[i] <= target) {
                    chosen.push_back(i); 
                    recursion(candidates, target - candidates[i], result, chosen);
                    chosen.pop_back();
                }
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> chosen;
        recursion(candidates, target, result, chosen);    
        for (int i = 0; i < result.size(); ++ i) {
            for (int j = 0; j < result[i].size(); ++ j) {
                result[i][j] = candidates[result[i][j]];
            }
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: recursion
 * 
 * */
