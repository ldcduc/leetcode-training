/* Problem url: https://leetcode.com/problems/duplicate-zeros
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        for (int i = 0; i < arr.size(); ++ i) {
            if (arr[i] == 0) {
                for (int j = arr.size() - 1; j > i; -- j) {
                    arr[j] = arr[j - 1];
                }
                ++ i;    
            }    
        }
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: array
 * 
 * */
