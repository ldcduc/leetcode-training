/* Problem url: https://leetcode.com/problems/permutations-ii
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        result.push_back(nums);
        bool hasSolution = true;
        while (hasSolution) {
            hasSolution = false;
            for (int i = nums.size() - 1 - 1; i >= 0; -- i) {
                if (nums[i] < nums[i + 1]) {
                    hasSolution = true;
                    int k = nums.size() - 1;
                    for (; nums[k] <= nums[i]; -- k);
                    swap(nums[i], nums[k]);
                    int l = i + 1, r = nums.size() - 1;
                    while (l < r) {
                        swap(nums[l], nums[r]);
                        ++ l;
                        -- r;
                    }
                    // Check if this permutation different from the previous one
                    for (int i = 0; i < nums.size(); ++ i) {
                        if (nums[i] != result.back()[i]) {
                            result.push_back(nums); 
                            break; 
                        }
                    }
                    break;
                }
            }
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: array, permutation
 * 
 * */
