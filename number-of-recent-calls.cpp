/* Problem url: https://leetcode.com/problems/number-of-recent-calls
 * Code by: ldcduc
 * */
/* Begin of Solution */
class RecentCounter {
public:
    vector<int> V;
    int cnt;
    RecentCounter() {
        cnt = 0;
    }
    
    int ping(int t) {
        V.push_back(t);
        ++ cnt;
        vector<int>::iterator it = lower_bound(V.begin(), V.end(), t - 3000);
        return cnt - (it - V.begin());
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: binary search
 * 
 * */
