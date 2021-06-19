/* Problem url: number-of-longest-increasing-subsequence
 * Code by: ldcduc
 * */
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int result = 0, LIS = 0;
        vector<int> count_(nums.size() + 1, 0);
        vector<int> len(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++ i) {
            len[i] = 1;
            for (int j = 0; j < i; ++ j) {
                if (nums[j] < nums[i]) {
                    if (len[j] + 1 > len[i]) {
                        len[i] = len[j] + 1;
                        count_[i] = count_[j];
                    } else if (len[j] + 1 == len[i]) {
                        count_[i] += count_[j];
                    }
                }
            }
            if (len[i] == 1) {
                count_[i] = 1;
            }
            if (len[i] > LIS) {
                LIS = len[i];
                result = count_[i];
            } else if (len[i] == LIS) {
                result += count_[i];
            }
        }
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: LIS, dynamic programming
 * 
 * */

