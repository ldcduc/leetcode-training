/* Problem url: https://leetcode.com/problems/degree-of-an-array
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int degree = 0, result, optimized = false;
        vector<vector<int>> freq(50000);
        vector<vector<int>> freq2(50000);
        for (int i = 0; i < nums.size(); ++ i) {
            freq[nums[i]].push_back(i);
            degree = degree > freq[nums[i]].size() ? degree : freq[nums[i]].size();
        }
        for (int i = 0; i < nums.size(); ++ i) {
            freq2[nums[i]].push_back(i);
            int t = freq2[nums[i]].size();
            if (t >= degree) {
                if (!optimized || i - freq2[nums[i]][t - degree] + 1 < result) {
                    result = i - freq2[nums[i]][t - degree] + 1; 
                    optimized = true;
                }    
            }
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: array
 * 
 * */
