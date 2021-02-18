/* Problem url: https://leetcode.com/problems/arithmetic-slices
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int result = 0;
        if (A.size() > 2) {
            int last_diff = A[1] - A[0], cur_diff, cnt = 0;
            for (int i = 2; i < A.size(); ++ i) {
                cur_diff = A[i] - A[i - 1];
                if (last_diff == cur_diff) {
                    ++ cnt; 
                    cout << i << ' ' << cnt << endl;
                } else {
                    cnt = 0;
                    last_diff = cur_diff;
                }
                result += cnt;
            }
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: 
 * 
 * */
