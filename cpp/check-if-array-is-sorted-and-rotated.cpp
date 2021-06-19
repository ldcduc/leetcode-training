/* Problem url: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    bool check(vector<int>& nums) {
        int dem = 0;
        vector<int> tmp;
        for (int i = 1; i < nums.size(); ++ i) {
            if (nums[i - 1] > nums[i]) {
                tmp.push_back(i);
            }
        }    
        if (tmp.size() == 0) {
            return true;
        } else if (tmp.size() > 1) {
            return false;
        }
        int x = tmp[0];
        vector<int> a;
        for (int i = 0; i < nums.size(); ++ i) {
            a.push_back(nums[(i + x) % nums.size()]);
        }
        for (int i = 1; i < nums.size(); ++ i) {
            if (a[i] < a[i - 1]) {
                return false;
            }
        }
        return true;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: array
 * 
 * */
