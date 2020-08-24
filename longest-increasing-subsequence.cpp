/* Problem url: https://leetcode.com/problems/longest-increasing-subsequence
 * Code by: ldcduc
 * */
class Solution {
public:
    int* pos, maxLIS = 0;
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        pos = (int*) calloc(n + 1, sizeof(int));
        for (int i = 0; i < n; ++ i) {
            int l = 1, r = maxLIS, m, tmp = 0;
            while (l <= r) {
                m = (l + r) >> 1;
                if (nums[pos[m]] < nums[i]) {
                    tmp = m;
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            if (maxLIS < tmp + 1) {
                maxLIS = tmp + 1;
                pos[tmp + 1] = i;
            } else if (nums[pos[tmp + 1] > nums[i]]) {
                pos[tmp + 1] = i;
            }
        } 
        return maxLIS;
    }
    ~Solution() {
        free(pos);
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: LIS
 * 
 * */
