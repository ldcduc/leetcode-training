/* Problem url: https://leetcode.com/problems/making-a-large-island
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j, int label) {
        if (!(i < 0 || j < 0 || i == grid.size() || j == grid[0].size())) {
            if (grid[i][j] == 1 && visited[i][j] == 0) {
                visited[i][j] = label;
                int result = 1;
                result += dfs(grid, visited, i - 1, j, label);
                result += dfs(grid, visited, i + 1, j, label);
                result += dfs(grid, visited, i, j - 1, label);
                result += dfs(grid, visited, i, j + 1, label);
                return result;
            }
        }
        return 0;
    } 
    int merge(vector<pair<int, int>> &v) {
        int result = 0, lastLabel = v[0].first - 1; 
        for (int i = 0; i < v.size(); ++ i) {
            if (v[i].first != lastLabel) {
                lastLabel = v[i].first;
                result += v[i].second;
            }
        }
        return result + 1;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector(n, 0));
        vector<int> cnt(1, 0);
        int result = 1;
        for (int i = 0, label = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (grid[i][j] == 1 && visited[i][j] == 0) {
                    ++ label;
                    int islandSize = dfs(grid, visited, i, j, label);
                    cnt.push_back(islandSize); 
                    result = max(result, islandSize);
                }
            }
        }
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (!grid[i][j]) {
                    vector<pair<int, int>> tmp;
                    if (i > 0) {
                        tmp.push_back(make_pair(visited[i - 1][j], cnt[visited[i - 1][j]]));
                    }
                    if (i + 1 < m) {
                        tmp.push_back(make_pair(visited[i + 1][j], cnt[visited[i + 1][j]]));
                    } 
                    if (j > 0) {
                        tmp.push_back(make_pair(visited[i][j - 1], cnt[visited[i][j - 1]]));
                    }
                    if (j + 1 < n) {
                        tmp.push_back(make_pair(visited[i][j + 1], cnt[visited[i][j + 1]]));
                    }
                    if (!tmp.empty()) {
                        sort(tmp.begin(), tmp.end());
                        result = max(result, merge(tmp));
                    }
                }
            }
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: graph, dfs, bfs
 * 
 * */
