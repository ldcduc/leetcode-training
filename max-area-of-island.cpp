/* Problem url: https://leetcode.com/problems/max-area-of-island
 * Code by: ldcduc
 * */
/* Begin of Solution */
class DFSSolution {
public:
    int Dx[4] = {-1, 0, 1, 0}, Dy[4] = {0, 1, 0, -1};
    int visit(vector<vector<int>>& grid, int x, int y) {
        int result = 1;
        grid[x][y] = 0;
        for (int dir = 0; dir < 4; ++ dir) {
            int newX = x + Dx[dir], newY = y + Dy[dir];
            if (0 <= newX && 0 <= newY && newX < grid.size() && newY < grid[0].size() && grid[newX][newY]) {
                result += visit(grid, newX, newY);
            }
        } 
        return result;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int result = 0;
        for (int i = 0; i < grid.size(); ++ i) {
            for (int j = 0; j < grid[0].size(); ++ j) {
                if (grid[i][j]) {
                    result = max(result, visit(grid, i, j));
                }    
            }
        }
        return result;
    }
};
class BFSSolution {
public:
    int Dx[4] = {-1, 0, 1, 0}, Dy[4] = {0, 1, 0, -1};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int result = 0;
        queue<pair<int, int>> Q;
        for (int i = 0; i < grid.size(); ++ i) {
            for (int j = 0; j < grid[0].size(); ++ j) {
                if (grid[i][j]) {
                    int count = 0;
                    Q.push(make_pair(i, j));
                    grid[i][j] = 0;
                    while (!Q.empty()) {
                        int x = Q.front().first, y = Q.front().second;
                        ++ count;
                        Q.pop();
                        for (int dir = 0; dir < 4; ++ dir) {
                            int newX = x + Dx[dir], newY = y + Dy[dir];
                            if (0 <= newX && 0 <= newY && newX < grid.size() && newY < grid[0].size() && grid[newX][newY]) {
                                Q.push(make_pair(newX, newY));
                                grid[newX][newY] = 0;
                            }
                        }
                    }
                    result = max(result, count);
                }
            }
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: depth first search, breadth first search
 * 
 * */
