/* Problem url: https://leetcode.com/problems/closest-subsequence-sum
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int find(vector<int> &sum, int val, int goal) {
        int result = abs(goal);
        int l = 0, r = sum.size() - 1;
        while (l <= r) {
            int m = (l + r) >> 1;
            result = min(result, abs(sum[m] + val - goal));
            if (sum[m] + val > goal) {
                r = m - 1;
            } else if (sum[m] + val < goal) {
                l = m + 1;
            } else {
                return 0;
            }
        }        
        return result; 
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        int result = abs(goal);
        int n = nums.size(), h = (nums.size() + 1) / 2;
        int k = n - h;     
        vector<int> sum(1 << h, 0);
        for (int i = 0, state = 1; i < h; ++ i, state <<= 1) {
            sum[state] = nums[i];        
        }
        for (int i = 1; i < (1 << h); ++ i) {
            sum[i] = sum[i - (i & -i)] + sum[i & -i];            
        }
        sort(sum.begin(), sum.end());
        vector<int> sum2(1 << k, 0);
        for (int i = 0, state = 1; i < k; ++ i, state <<= 1) {
            sum2[state] = nums[i + h];
        } 
        for (int i = 1; i < (1 << k); ++ i) {
            sum2[i] = sum2[i - (i & -i)] + sum2[i & -i];            
        }
        for (int i = 0; i < (1 << k); ++ i) {
            result = min(result, abs(sum2[i] - goal));  
            result = min(result, find(sum, sum2[i], goal));
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: half set 
 * 
 * */
