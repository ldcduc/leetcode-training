/* Problem url: https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int result = 0;
        A.push_back(1e9 + 1); // infinity
        vector<int> left(A.size(), 0);
        stack<int> S;
        for (int i = 0; i < A.size(); ++ i) {
            left[i] = i;
            while (!S.empty() && A[S.top()] <= A[i]) {
                int t = (S.top() - left[S.top()] + 1) * (i - 1 - S.top() + 1);
                result += (L <= A[S.top()] && A[S.top()] <= R) * t;
                left[i] = left[S.top()];
                S.pop();
            }
            S.push(i);
        }
        return result;
    }
};

/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: stack
 * 
 * */
