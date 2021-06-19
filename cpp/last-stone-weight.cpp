/* Problem url: https://leetcode.com/problems/last-stone-weight
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> Q;
        for (int i = 0; i < stones.size(); ++ i) {
            Q.push(stones[i]);
        }
        while (Q.size() > 1) {
            int y = Q.top();
            Q.pop(); 
            int x = Q.top();
            Q.pop(); 
            if (x != y) {
                Q.push(y - x);
            }
        }
        return Q.empty() ? 0 : Q.top();
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: heap
 * 
 * */
