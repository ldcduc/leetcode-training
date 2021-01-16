/* Problem url: https://leetcode.com/problems/kth-largest-element-in-an-array
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> Q;
        for (auto num : nums) {
            Q.push(num);
        }
        for (int i = 1; i < k; ++ i) {
            Q.pop();
        }
        return Q.top();
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: heap
 * 
 * */
