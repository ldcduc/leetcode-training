/* Problem url: https://leetcode.com/problems/valid-mountain-array
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int tmp = -1;
        for (int i = 1; i < A.size(); ++ i) {
            if (A[i - 1] > A[i]) {
                tmp = i;
                break;
            } else if (A[i - 1] == A[i]) {
                return false;
            }
        }    
        if (tmp > 1) {
            for (int i = tmp + 1; i < A.size(); ++ i) {
                if (A[i - 1] <= A[i]) {
                    return false;
                }
            }
        } else {
            return false;
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
