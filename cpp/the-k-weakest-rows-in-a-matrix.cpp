/* Problem url: https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;    
        for (int row = 0; row < mat.size(); ++ row) {
            if (mat[row].back() == 1) {
                Q.push(make_pair(mat[row].size(), row));  
            } else {
                for (int col = 0; col < mat[row].size(); ++ col) {
                    if (mat[row][col] == 0) {
                        Q.push(make_pair(col, row));
                        break;
                    }
                }
            }
        }
        vector<int> result;
        for (int i = 0; i < k; ++ i) {
            result.push_back(Q.top().second);
            Q.pop();
        }
        return result;       
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: heap
 * 
 * */
