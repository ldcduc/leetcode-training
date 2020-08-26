/* Problem url: https://leetcode.com/problems/increasing-subsequences
 * Code by: ldcduc
 * */
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> tmp;
        vector<vector<int>> result;
        int n = nums.size();
        for (int state = 2; state < (1 << n); ++ state) {
            bool ok = true;
            vector<int> bits;
            for (int bit = 0; bit < n; ++ bit) {
                if ((state >> bit) & 1) {
                    if (!bits.empty() && nums[bits.back()] > nums[bit]) {
                        ok = false;
                        break;
                    }
                    bits.push_back(bit);
                }
            }
            if (ok && bits.size() > 1) {
                for (int i = 0; i < bits.size(); ++ i) {
                    bits[i] = nums[bits[i]];
                }
                tmp.push_back(bits);
            }
        }
        sort(tmp.begin(), tmp.end());
        for (int i = 0; i < tmp.size(); ++i) {
            if (i == 0 || tmp[i] != tmp[i - 1]) {
                result.push_back(tmp[i]);
            }
        }
        return result;
    }
};

/*
 * Comment by ldcduc
 * Suggested tags: 
 * 
 * */

