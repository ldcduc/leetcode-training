/* Problem url: https://leetcode.com/problems/combination-sum-iii
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    void recursion(int k, int n, vector<vector<int>>& result, vector<int>& chosen) {
        if (k == 0) {
            if (n == 0) {
                result.push_back(chosen);
            }    
        } else {
            for (int i = chosen.empty() ? 1 : chosen.back() + 1; i <= 9; ++ i) {
                chosen.push_back(i);
                recursion(k - 1, n - i, result, chosen);
                chosen.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> chosen;
        recursion(k, n, result, chosen);
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: recursion
 * 
 * */
