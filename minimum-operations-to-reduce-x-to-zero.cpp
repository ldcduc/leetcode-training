/* Problem url: https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    void minimize(int &x, int y) {
        if (y < x) {
            x = y;
        }
    }
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int result = n + 1;
        unordered_map<int, int> M;
        M[0] = n;
        for (int i = n - 1, sum = 0; i >= 0; -- i) {
            sum += nums[i];
            if (M.count(sum) == 0) {
                M[sum] = i;
            }
        }
        if (M.count(x) > 0) {
            result = n - M[x];
        }
        for (int i = 0, sum = 0; i < n; ++ i) {
            sum += nums[i];
            if (sum == x) {
                minimize(result, i + 1);
            }            
            if (M.count(x - sum) > 0) {
                minimize(result, i + 1 + n - M[x - sum]);
            }
        }
        return result > n ? -1 : result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: hash map, binary search
 * 
 * */
