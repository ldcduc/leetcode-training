/* Problem url: https://leetcode.com/problems/jump-game-iii
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int recursion(vector<int>& arr, vector<int>& visited, int index) {
        if (0 <= index && index < arr.size()) {
            if (visited[index]) {
                return visited[index];
            }    
            if (arr[index] == 0) {
                return visited[index] = 1;    
            }
            visited[index] = -1;
            int left = recursion(arr, visited, index - arr[index]);
            int right = recursion(arr, visited, index + arr[index]);
            if (left == 1 || right == 1) {
                visited[index] = 1;
                return 1;
            } else {
                return -1;
            }
        }    
        return false;
    }
    bool canReach(vector<int>& arr, int start) {
        vector<int> visited(arr.size(), 0);
        int t = recursion(arr, visited, start);
        return t == 1;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: recursion, memoization
 * 
 * */
