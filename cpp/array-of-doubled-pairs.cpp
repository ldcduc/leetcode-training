/* Problem url: https://leetcode.com/problems/array-of-doubled-pairs
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        unordered_map<int, int> M;
        priority_queue<pair<int, int>> Q;
        for (int i = 0; i < A.size(); ++ i) {
            ++ M[A[i]];         
            Q.push(make_pair(abs(A[i]), i));
        }    
        while (!Q.empty()) {
            int maxVal = A[Q.top().second];
            Q.pop();
            if (M[maxVal] > 0) {
                -- M[maxVal];
                if (abs(maxVal) % 2 == 0 && M[maxVal / 2] > 0) {
                    -- M[maxVal / 2];
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: heap
 * 
 * */
