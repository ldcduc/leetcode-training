/* Problem url: https://leetcode.com/problems/peak-index-in-a-mountain-array
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 1, r = arr.size() - 2;
        while (l <= r) {
            int m = (l + r) / 2;
            if (arr[m - 1] < arr[m] && arr[m] > arr[m + 1]) {
                return m;
            } else if (arr[m] < arr[m + 1]) {
                l = m + 1;    
            } else {
                r = m - 1;
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
