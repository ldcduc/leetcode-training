/* 
 * Problem url: https://leetcode.com/problems/unique-paths-iii/
 * Code by ldcduc
 * */
int f[1<<20][20];
int marked[1<<20][20];
class Solution {
private:
    int height, width;
    const int X[4] = {-1, 0, 0, 1};
    const int Y[4] = {0, -1, 1, 0};
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        height = grid.size();
        width = grid[0].size();

        for (int i=0; i<1<<(height*width); ++i) {
            for (int j=0; j<height*width; ++j)
                f[i][j] = marked[i][j] = 0;
        }

        int start_ = 0, start_x, start_y;
        int end_idx;
        for (int i=0; i<height; ++i)
            for (int j=0; j<width; ++j)
                if (grid[i][j] == 1) {
                    start_x = i;
                    start_y = j;
                    start_ |= 1 << (i * width + j);
                } else if (grid[i][j] == 2) {
                    end_idx = (i * width + j);
                } else if (grid[i][j] == -1) {
                    start_ |= 1 << (i * width + j);
                }
        f[start_][start_x * width + start_y] = 1;
        marked[start_][start_x * width + start_y] = true;

        queue<pair<int, pair<int, int> > > q;
        q.push(make_pair(start_, make_pair(start_x, start_y)));
        while (!q.empty()) {
            int state_  = q.front().first, x = q.front().second.first, y = q.front().second.second;
            q.pop();

            for (int dir=0; dir<4; ++dir) {
                int next_x = x + X[dir];
                int next_y = y + Y[dir];
                int next_idx = next_x * width + next_y;
                if (next_x < 0 || next_y < 0 || next_x == height || next_y == width)
                    continue;
                int next_state = state_ | (1 << next_idx);
                if (state_ == next_state)
                    continue;


                f[state_ | (1 << next_idx)][next_idx] += f[state_][x * width + y];
                if (!marked[state_ | (1 << next_idx)][next_idx]) {
                    marked[state_ | (1 << next_idx)][next_idx] = true;
                    q.push(make_pair(state_ | (1 << next_idx), make_pair(next_x, next_y)));
                }
            }
        }
        int result = f[(1 << (width * height)) - 1][end_idx];
        return result;
    }
};


/* 
 * Comment by ldcduc
 * Suggested tags: DP, bitmask DP
 * Bitmask DP is hard to implement, do it with care
 * Pay attention in dynamic allocated memory, I have met some errors with heap buffer overflow, heap segmentation fault.
 * Use too large vectors may also cause Time Limited Exceed
 * */
 * */
