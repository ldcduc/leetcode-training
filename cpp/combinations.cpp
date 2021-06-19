/* Problem url: https://leetcode.com/problems/combinations
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    void recursion(vector<vector<int>>& result, vector<int>& combination, vector<bool>& used, int n, int k, int index) {
        if (index < k) {
            for (int num = (index > 0 ? combination[index - 1] : 0) + 1; num <= n; ++ num) {
                if (!used[num - 1]) {
                    used[num - 1] = true;
                    combination[index] = num;
                    recursion(result, combination, used, n, k, index + 1);
                    used[num - 1] = false;
                }
            }    
        } else {
            result.push_back(combination);
        }   
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> combination(k);
        vector<bool> used(n, 0);
        recursion(result, combination, used, n, k, 0); 
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: recursion
 * 
 * */
