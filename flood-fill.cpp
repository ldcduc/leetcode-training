/* Problem url: https://leetcode.com/problems/flood-fill
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] != newColor) {
            int startColor = image[sr][sc];    
            int Dx[] = {-1, 0, 1, 0}, Dy[] = {0, 1, 0, -1};
            queue<pair<int, int>> Q;
            Q.push(make_pair(sr, sc));
            image[sr][sc] = newColor;
            while (!Q.empty()) {
                int row = Q.front().first, col = Q.front().second;
                Q.pop();
                for (int dir = 0; dir < 4; ++ dir) {
                    int r = row + Dx[dir], c = col + Dy[dir];
                    if (0 <= r && 0 <= c && r < image.size() && c < image[0].size() && image[r][c] == startColor) {
                        image[r][c] = newColor;
                        Q.push(make_pair(r, c));
                    }
                } 
            }
        }
        return image;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: depth first search, breadth first search
 * 
 * */
