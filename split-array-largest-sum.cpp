/* Problem url: https://leetcode.com/problems/split-array-largest-sum
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int l = 0, r = 1000000000, n = nums.size(), result;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int max_num = nums[0], min_num = nums[0], interval = 1;
            long long sum = 0;
            for (int i = 0; i < n; ++ i) {
                if (sum + nums[i] <= mid) {
                    sum += nums[i];
                } else if (nums[i] <= mid) {
                    ++ interval;
                    sum = nums[i];
                } else {
                    interval = m + 1;
                    break;
                }
            }
            if (interval <= m) {
                r = mid - 1;
                result = mid;
            } else {
                l = mid + 1;
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
