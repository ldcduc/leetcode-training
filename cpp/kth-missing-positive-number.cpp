/* Problem url: https://leetcode.com/problems/kth-missing-positive-number
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int index = 0, cnt = 0;
        for (int i = 1; i <= 2000; ++ i) {
            if (index < arr.size() && i == arr[index]) {
                ++ cnt;
                ++ index;
            } 
            if (i - cnt == k) {
                return i;
            }
        }
        return 0;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: 
 * 
 * */
