/* Problem url: https://leetcode.com/problems/array-nesting
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int res = 0, cur, count, prev;
        for (int i = 0; i < nums.size(); ++ i) {
            if (nums[i] == -1) continue;
            cur = nums[i], nums[i] = -1;
            count = 1; 
            while (nums[cur] != -1) {
                prev = cur;
                cur = nums[cur];
                nums[prev] = -1;
                ++ count;
            }
            
            res = max(res, count);
        }
        return res;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: dfs
 * 
 * */
