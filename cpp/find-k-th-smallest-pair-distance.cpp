/* Problem url: https://leetcode.com/problems/find-k-th-smallest-pair-distance
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());    
        int n = nums.size(), l = 0, r = nums.back() - nums[0];
        int result = r;
        while (l <= r) {
            int m = (l + r) >> 1;
            int cnt = 0;
            for (int start = 0, end = 0; start < n; ++ start) {
                while (end + 1 < n && nums[end + 1] - nums[start] <= m) {
                    ++ end;
                }    
                if (nums[end] - nums[start] <= m) {
                    cnt += end - start;
                }
            } 
            if (cnt >= k) {
                result = m;    
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: binary search
 * 
 * */
