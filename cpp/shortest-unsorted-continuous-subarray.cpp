/* Problem url: https://leetcode.com/problems/shortest-unsorted-continuous-subarray
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> tmp(nums);
        sort(tmp.begin(), tmp.end());
        int l = 0, r = -1;
        for (int i = 0; i < tmp.size(); ++ i) {
            if (tmp[i] != nums[i]) {
                l = i;
                break;
            }
        }
        for (int i = tmp.size() - 1; i >= 0; -- i) {
            if (tmp[i] != nums[i]) {
                r = i;
                break;
            }
        }
        return r - l + 1;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: array
 * 
 * */
