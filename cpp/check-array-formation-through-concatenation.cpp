/* Problem url: https://leetcode.com/problems/check-array-formation-through-concatenation
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, int> M;
        for (int i = 0; i < pieces.size(); ++ i) {
            for (auto num : pieces[i]) {
                M[num] = i;
            }
        }
        vector<int> piece = pieces[M[arr[0]]];
        int j = 0; // j - current index in piece
        for (int i = 0; i < arr.size(); ++ i) {
            if (arr[i] == piece[j]) {
                if (i + 1 < arr.size()) {
                    if (M.count(arr[i + 1]) == 0) { // arr[i + 1] does not exist in pieces
                        return false;
                    }
                    if (M[arr[i + 1]] == M[arr[i]]) { // Everything goes well
                        ++ j;
                    } else {
                        if (j != piece.size() - 1) { // Expect: piece to be changed
                            return false;
                        } else { // Change piece = new piece
                            piece = pieces[M[arr[i + 1]]];
                            j = 0;
                        }
                    }
                }    
            } else { // arr[i] != piece[j]
                return false;
            }
        }
        return true;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: 
 * 
 * */
