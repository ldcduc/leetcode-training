/* Problem url: https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int check(vector<int>& nums, int maxOperations, int result) {
        priority_queue<int> Q;
        for (int i = 0; i < nums.size(); ++ i) {
            Q.push(nums[i]);
        }    
        while (!Q.empty() && maxOperations > 0) {
            int val = Q.top();;
            Q.pop();
            if (val <= result) {
                return true;
            }
            int tmp = (val + result - 1) / result - 1;
            if (tmp > maxOperations) {
                return false;
            }
            maxOperations -= tmp;
        }
        return Q.empty() || Q.top() <= result;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int maxNum = nums[0];
        for (int i = 0; i < nums.size(); ++ i) {
            maxNum = max(nums[i], maxNum);
        }
        int l = 1, r = maxNum, m, result = maxNum;
        while (l <= r) {
            m = (l + r) >> 1;
            if (check(nums, maxOperations, m)) {
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
