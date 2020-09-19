/* Problem url: https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxVal, optimized = false;      
        for (int i = arr.size() - 1; i >= 0; -- i) {
            int val = arr[i];
            if (optimized) {
                arr[i] = maxVal;    
            } else {
                arr[i] = -1;
            }
            if (!optimized || val > maxVal) {
                maxVal = val;
                optimized = true;
            }
        }
        return arr;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: 
 * 
 * */
