/* Problem url: https://leetcode.com/problems/combination-sum-ii
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    set<vector<int>> setResult; 
    void recursion(int index, vector<int>& candidates, vector<int> &tmp, int remain) {
        if (remain <= 0) {
            if (remain == 0) {
                setResult.insert(tmp);
            } 
            return;
        }
        if (index < candidates.size()) {
            tmp.push_back(candidates[index]);
            recursion(index + 1, candidates, tmp, remain - candidates[index]);
            tmp.pop_back();
            recursion(index + 1, candidates, tmp, remain);
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());    
        vector<int> tmp;
        recursion(0, candidates, tmp, target);
        vector<vector<int>> result;
        for (auto item : setResult) {
            result.push_back(item);
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
