/* Problem url: https://leetcode.com/problems/friend-circles
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size(), res = 0;
        vector<bool> visited; 
        visited.resize(n, false);
        queue<int> q;
        for (int i = 0; i < n; ++ i) {
            if (visited[i] == false) {
                ++res;
                q.push(i);
                visited[i] = true;
                int cur;
                while (!q.empty()) {
                    cur = q.front();
                    q.pop();
                    for (int next = 0; next < n; ++ next) {
                        if (M[cur][next] && !visited[next]) {
                            q.push(next);
                            visited[next] = true;
                        }
                    }
                }
            }     
        }
        return res;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: breadth first search, graph
 * 
 * */
