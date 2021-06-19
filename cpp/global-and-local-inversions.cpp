/* Problem url: https://leetcode.com/problems/global-and-local-inversions
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        vector<pair<int, int>> tmp;        
        for (int i = 0; i < A.size(); ++ i) {
            tmp.push_back(make_pair(A[i], i));
        }
        sort(tmp.rbegin(), tmp.rend());
        bool global = false, local = 0;
        int minPos;
        for (int i = 0; i < A.size(); ++ i) {
            if (i) {
                global |= minPos < tmp[i].second - 1;
                minPos = min(minPos, tmp[i].second);
                // unrelevant
                local |= A[i-1] > A[i];
            } else {
                minPos = tmp[i].second;
            }
        }
        return !(global & local);
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: sorting, inversion, fun
 * 
 * */
