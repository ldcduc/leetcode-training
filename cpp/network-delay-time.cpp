/* Problem url: https://leetcode.com/problems/network-delay-time
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<pair<int, int>>> adj(N);
        for (auto item : times) {
            adj[item[0] - 1].push_back(make_pair(item[1] - 1, item[2]));
        }
        vector<int> distance(N);
        for (int i = 0; i < N; ++ i) {
            distance[i] = -1; // unvisited
        }
        priority_queue<pair<int, int>> Q;
        distance[-- K] = 0;
        Q.push(make_pair(0, K));
        while (!Q.empty()) {
            int source = Q.top().second, dist = -Q.top().first;
            Q.pop();
            if (dist == distance[source]) {
                for (auto item : adj[source]) {
                    if (distance[item.first] == -1 || dist + item.second < distance[item.first]) {
                        distance[item.first] = dist + item.second;
                        Q.push(make_pair(-distance[item.first], item.first));
                    }
                }    
            }
        }
        int result = -1;
        for (int i = 0; i < N; ++ i) {
            if (distance[i] == -1) {
                return -1;
            }
            result = max(result, distance[i]);
        }
        return result;
    }
};

/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: shortest path
 * 
 * */
