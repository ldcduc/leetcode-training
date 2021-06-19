/* Problem url: https://leetcode.com/problems/subsets-ii
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        unordered_map<string, bool> M;
        for (int state = 0; state < (1 << n); ++ state) {
            vector<int> a;
            for (int i = 0; i < n; ++ i) {
                if (state >> i & 1) {
                    a.push_back(nums[i]);
                }
            }
            string s = "";
            sort(a.begin(), a.end());
            for (auto item : a) {
                s += to_string(item);
            }
            if (M.count(s) == 0) {
                result.push_back(a);
                M[s] = true;
            }
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: hash_map
 * 
 * */
