/* Problem url: https://leetcode.com/problems/video-stitching
 * Code by: ldcduc
 * */
/* Begin of Solution */
class DynammicProgrammingSolution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(), clips.end(), [](vector<int>& x, vector<int>& y) {
            return x[0] == y[0] ? x[1] > y[1] : x[0] < y[0];
        });
        vector<int> dp(clips.size(), (int) 1e9);
        int result = 1e9;
        for (int i = 0; i < clips.size(); ++ i) {
            if (clips[i][0] == 0) {
                dp[i] = 1;    
            }
            for (int j = i - 1; j >= 0; -- j) {
                if (clips[i][0] <= clips[j][1]) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
            if (clips[i][1] >= T && dp[i] > 0 && dp[i] < result) {
                result = dp[i];
            }
        }
        return result < (int) 1e9 ? result : -1;
    }
};
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(), clips.end(), [](vector<int>& x, vector<int>& y) {
            return x[0] == y[0] ? x[1] > y[1] : x[0] < y[0];
        });
        vector<int> dp(clips.size(), (int) 1e9);
        int maxEnd = 0, result = 0, start = 0;
        for (auto clip : clips) {
            if (clip[1] >= maxEnd) {
                if (clip[0] > maxEnd) {
                    return -1;
                }
                if (clip[0] > start) {
                    start = maxEnd;
                    ++ result;
                }
                if (clip[1] >= T) {
                    return ++ result;
                }
                maxEnd = clip[1];
            }
        }
        return -1;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: dynamic programming
 * 
 * */
