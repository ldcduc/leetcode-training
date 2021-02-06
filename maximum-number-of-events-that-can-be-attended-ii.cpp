/* Problem url: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    vector<int> T;
    int Tsize;
    vector<int> dp;
    void update (int label, int index) {
        while (label <= Tsize) {
            if (dp[T[label]] < dp[index]) {
                T[label] = index;
            }
            label += label & - label;
        }
    }
    int getRes(int label, int index) {
        int result = 0;
        while (label > 0) {
            if (dp[T[label]] > dp[result]) {
                result = T[label];
            }
            label -= label & -label;    
        }
        return result;    
    }
    int maxValue(vector<vector<int>>& events, int k) {
        if (k == 1) {
            int result = 0;
            for (int i = 0; i < events.size(); ++ i) {
                result = max(result, events[i][2]);
            }
            return result;    
        }
        int n = events.size();
        vector<pair<int, pair<int, int>>> a;
        for (int i = 0; i < n; ++ i) {
            a.push_back({events[i][0],{i, 0}});
            a.push_back({events[i][1],{i, 1}});
        }         
        sort(a.begin(), a.end(), [](pair<int, pair<int, int>> x, pair<int, pair<int, int>> y) {
            return x.first < y.first;
        });
        int old = a[0].first - 1, new_ = 0;
        for (int i = 0; i < a.size(); ++ i) {
            if (a[i].first == old) {
                events[a[i].second.first][a[i].second.second] = new_;
            } else {
                old = a[i].first;
                ++ new_;
                events[a[i].second.first][a[i].second.second] = new_;
            }
        }
        T.resize(new_ + 1, 0);
        Tsize = new_;
        vector<pair<pair<int, int>, int>> Events(1);
        for (int i = 0; i < n; ++ i) {
            Events.push_back({{events[i][0], events[i][1]}, events[i][2]});
        }
        sort(Events.begin(), Events.end(), [](pair<pair<int, int>, int> x, pair<pair<int, int>, int> y) {
            return x.first.first < y.first.first;
        });
        dp.resize(n + 1, 0);
        int index = 0;                     
        vector<int> indexes;
        vector<int> trace(n + 1);                     
        for (int i = 1; i <= n; ++ i) {
            int t = getRes(Events[i].first.first - 1, i);
            trace[i] = t;
            dp[i] = dp[t] + Events[i].second;
            update(Events[i].first.second, i);
            if (dp[i] > dp[index]) {
                indexes.clear();
                indexes.push_back(i);
                index = i;
            } else if (dp[i] == dp[index]) {
                indexes.push_back(i);
            }    
        }
        int result = 0;
        for (auto num : indexes) {
            int res = 0;
            index = num; 
            priority_queue<int> Q;                             
            while (index > 0) {
                Q.push(Events[index].second);
                index = trace[index];   
            }                     
            k = k < Q.size() ? k : Q.size();
            for (int i = 0; i < k; ++ i) {
                res += Q.top();
                Q.pop();    
            }                             
            result = max(result, res);
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
