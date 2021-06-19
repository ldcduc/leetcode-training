/* Problem url: https://leetcode.com/problems/minimum-absolute-difference
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> result;
        for (int i = 1; i < arr.size(); ++ i) {
            if (result.empty() || arr[i] - arr[i - 1] < result.back()[1] - result.back()[0]) {
                result.clear();
                result.push_back(vector<int> {arr[i - 1], arr[i]});
            } else if (arr[i] - arr[i - 1] == result.back()[1] - result.back()[0]) {
                result.push_back(vector<int> {arr[i - 1], arr[i]});
            }
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: array, sorting
 * 
 * */
