/* Problem url: https://leetcode.com/problems/find-the-distance-value-between-two-arrays
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int result = 0, n = arr2.size();
        for (auto num : arr1) {
            int index = lower_bound(arr2.begin(), arr2.end(), num) - arr2.begin();
            bool ok = true;
            ok &= !(index < n && arr2[index] - num <= d);
            ok &= !(index > 0 && num - arr2[index - 1] <= d);
            result += ok;
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
