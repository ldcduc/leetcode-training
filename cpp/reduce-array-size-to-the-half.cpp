/* Problem url: https://leetcode.com/problems/reduce-array-size-to-the-half
 * Code by: ldcduc
 * */
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int result = 0;
        int n = arr.size();
        priority_queue<int> q;

        sort(arr.begin(), arr.end());
        if (arr.size()) {
            int lastVal = arr[0], cnt = 0;
            for (int i = 0; i < n; ++ i) {
                if (arr[i] == lastVal) {
                    ++cnt;
                } else {
                    q.push(cnt);
                    cnt = 1;
                    lastVal = arr[i];
                }
            }
            q.push(cnt);
        }
        int sum = 0;
        while (!q.empty()) {
            sum += q.top();
            q.pop();
            ++result;
            if (sum >= n/2) {
                break;
            }
        }
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags:
 * 
 * */

