/* Problem url: https://leetcode.com/problems/reverse-pairs
 * Code by: ldcduc
 * */
class Solution {
public:
    vector<int> BIT;
    int maxVal;

    void update(int val) {
        while (val <= maxVal) {
            ++BIT[val];
            val += val & -val;
        }
    }
    int count(int val) {
        int result = 0;
        val = min(val, maxVal);
        while (val) {
            result += BIT[val];
            val -= val & -val;
        }
        return result;
    }
    int reversePairs(vector<int>& nums) {
        int result = 0, n = nums.size();
        if (n) {
            vector<pair<long long, int> > tmp(n);
            for (int i = 0; i < n; ++ i) {
                nums.push_back(0);
                tmp[i] = make_pair(nums[i], i);
                tmp.push_back(make_pair(1ll * nums[i] * 2, i + n));
            }
            sort(tmp.begin(), tmp.end());
            long long lastVal = tmp[0].first - 1;
            int newVal = 0;
            for (int i = 0; i < n * 2; ++ i) {
                if (tmp[i].first != lastVal) {
                    ++newVal;
                    lastVal = tmp[i].first;
                }
                nums[tmp[i].second] = newVal;
            }
            this->maxVal = newVal;
            this->BIT.resize(newVal + 1, 0);
            for (int i = 0; i < n; ++ i) {
                result += i - count(nums[i + n]);
                update(nums[i]);
            }
        }
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: binary indexed tree
 * 
 * */
