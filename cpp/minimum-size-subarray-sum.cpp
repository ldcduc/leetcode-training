/* Problem url: https://leetcode.com/problems/minimum-size-subarray-sum
 * Code by: ldcduc
 * */
/* Begin of Solution */
class O_n_Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int result = nums.size() + 1;
        int l = 0, sum = 0;    
        for (int r = 0; r < nums.size(); ++ r) {
            sum += nums[r];
            if (sum >= s) {
                result = min(result, r - l + 1);    
                do {
                    sum -= nums[l ++];    
                    if (sum >= s) {
                        result = min(result, r - l + 1);    
                    }
                } while (l <= r && sum >= s);
            }
        } 
        return result > nums.size() ? 0 : result;
    }
};
class O_nlogn_Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int result = nums.size() + 1, n = nums.size();
        vector<int> sums(1, 0);
        for (auto num : nums) {
            sums.push_back(sums.back() + num);
        }
        int l = 1, r = n;
        while (l <= r) {
            int m = (l + r) >> 1;
            bool check = false;
            for (int i = m; i <= n; ++ i) {
                if (sums[i] - sums[i - m] >= s) {
                    check = true;
                    break;
                }
            }
            if (check) {
                result = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return result > nums.size() ? 0 : result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: two pointers, binary search
 * 
 * */
