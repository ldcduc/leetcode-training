/* Problem url: https://leetcode.com/problems/next-greater-element-ii
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        for (int i = 0; i < n - 1; ++ i) {
            nums.push_back(nums[i]);
        }
        stack<int> S;
        for (int i = 0; i < nums.size(); ++ i) {
            while (!S.empty() && nums[S.top() % n] < nums[i]) {
                if (result[S.top() % n] == -1) {
                    result[S.top() % n] = i % n;
                } 
                S.pop();
            }
            S.push(i);
        } 
        for (int i = 0; i < n; ++ i) {
            result[i] = result[i] != -1 ? nums[result[i]] : -1;
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: stack
 * 
 * */
