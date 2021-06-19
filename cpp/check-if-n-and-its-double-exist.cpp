/* Problem url: https://leetcode.com/problems/check-if-n-and-its-double-exist
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        for (int i = 0; i < arr.size(); ++ i) {
            for (int j = 0; j < arr.size(); ++ j) {
                if (i != j && arr[i] * 2 == arr[j]) {
                    return true;
                }
            }
        }    
        return false;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: array
 * 
 * */
