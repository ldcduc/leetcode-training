/* Problem url: https://leetcode.com/problems/jump-game-ii
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        vector<int> furthest(n);

        furthest[0] = nums[0];
        for (int i = 1; i < n; ++ i) {
            furthest[i] = min(i + nums[i], n - 1);
            furthest[i] = max(furthest[i], furthest[i - 1]);
        }

        dp[n - 1] = 0;
        priority_queue<pair<int, int>> Q;
        Q.push(make_pair(0, n - 1));
        for (int i = n - 2; i >= 0; -- i) {
            dp[i] = n + 1;
            while (!Q.empty() && Q.top().second > furthest[i]) {
                Q.pop();
            }
            if (!Q.empty()) {
                dp[i] = -Q.top().first + 1;
            }
            Q.push(make_pair(-dp[i], i)); // Priority_queue is a max-heap --> -dp[i] is max --> dp[i] is min
        }
        return dp[0];
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: heap 
 * 
 * */
