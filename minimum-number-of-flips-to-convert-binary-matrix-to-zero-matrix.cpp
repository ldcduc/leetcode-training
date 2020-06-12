/* 
 * Problem url: https://leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/
 * Code by ldcduc
 * */

class Solution {
private:
    int m, n;
public:
    int flip(int state, int x, int y) {
        int result = state;
        int index = x * this->n + y;
        result = result = result ^ (1 << index);
        if (x - 1 >= 0) {
            index = (x - 1) * this->n + y;
            result = result ^ (1 << index);
        }
        if (x + 1 < this->m) {
            index = (x + 1) * this->n + y;
            result = result ^ (1 << index);
        }
        if (y - 1 >= 0) {
            index = x * this->n + y - 1;
            result = result ^ (1 << index);
        }
        if (y + 1 < n) {
            index = x * this->n + y + 1;
            result = result ^ (1 << index);
        }
        return result;
    }
    int minFlips(vector<vector<int>>& mat) {
        this->m = mat.size();
        this->n = mat[0].size();
        int starting_state = 0;
        for (int i=0; i<this->m; ++i) 
            for (int j=0; j<this->n; ++j) {
                starting_state |= (mat[i][j] == 1) << (i * this->n + j);
            }
        vector<int> marked(1 << (this->m * this->n), 0);
        marked[starting_state] = 1;
        queue<int> q;
        q.push(starting_state);
        while (!q.empty()) {
            int cur_state = q.front(); q.pop();
            for (int i=0; i<this->m; ++i)
                for (int j=0; j<this->n; ++j) {
                    int next_state = this->flip(cur_state, i, j);
                    if (!marked[next_state]) {
                        marked[next_state] = marked[cur_state] + 1;
                        q.push(next_state);
                    }
                }
        }
        return marked[0] - 1;
    }
};

/* 
 * Comment by ldcduc
 *
 * */
