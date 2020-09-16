/* Problem url: https://leetcode.com/problems/create-target-array-in-the-given-order
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n = nums.size();
        vector<int> result(n);
        for (int i = 0; i < n; ++ i) {
            for (int j = i; j > index[i]; -- j) {
                result[j] = result[j - 1];
            }
            result[index[i]] = nums[i];
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: ad-hoc, implementation
 * 
 * */
