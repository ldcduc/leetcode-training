/* Problem url: https://leetcode.com/problems/next-greater-element-i
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextRight;
        vector<int> result(nums1.size());
        stack<int> S;
        for (int i = 0; i < nums2.size(); ++ i) {
            while (!S.empty() && S.top() < nums2[i]) {
                nextRight[S.top()] = nums2[i];
                S.pop();
            }   
            S.push(nums2[i]);
        }
        for (int i = 0; i < nums1.size(); ++ i) {
            result[i] = nextRight.count(nums1[i]) == 0 ? -1 : nextRight[nums1[i]];
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
