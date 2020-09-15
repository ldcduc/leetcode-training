/* Problem url: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int l = 1, r = 0, res;
        for (auto weight : weights) {
            l = max(l, weight);
            r += weight;
        }
        while (l <= r) {
            int m = (l + r) >> 1;
            int day = 1, load = 0;
            for (auto weight : weights) {
                if (load + weight > m) {
                    load = 0;
                    ++day;
                }
                load += weight;
            }
            if (day <= D) {
                cout << m << ' ' << day << endl;
                res = m;    
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return res;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: binary search
 * 
 * */
