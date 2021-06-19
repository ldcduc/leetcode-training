/* Problem url: https://leetcode.com/problems/maximum-score-from-removing-stones
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int result = 0;
        priority_queue<int> Q;
        Q.push(a);
        Q.push(b);
        Q.push(c);
        while (true) {
            int a = Q.top(); Q.pop();
            int b = Q.top(); Q.pop();
            if (a > 0 && b > 0) {
                ++ result;
                Q.push(a - 1);
                Q.push(b - 1);
            } else {
                break;
            }
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: heap
 * 
 * */
