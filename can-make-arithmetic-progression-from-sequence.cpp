/* Problem url: https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());    
        for (int i = 1; i < arr.size() - 1; ++ i) {
            if (arr[i] - arr[i - 1] != arr[i + 1] - arr[i]) {
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
