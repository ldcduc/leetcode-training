/* Problem url: https://leetcode.com/problems/longest-happy-string
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string result = "";
        int cnt[3] = {0};
        pair<int, int> remain[3] = {{a, 0}, {b, 1}, {c, 2}};
        int last_ch = -1;
        bool continue_ = true;
        while (continue_) {
            continue_ = false;
            sort(remain, remain + 3, greater<pair<int, int>>());
            for (int i = 0; i < 3; ++ i) {
                int ch = remain[i].second;
                if (remain[i].first > 0 && cnt[ch] < 2) {
                    result += char(ch + 'a');
                    for (int t = 0; t < 3; ++ t) {
                        cnt[t] = t == ch ? cnt[t] + 1 : 0;
                    }
                    last_ch = ch;
                    -- remain[i].first;
                    continue_ = true;
                    break;
                }    
            }
        } 
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: string
 * 
 * */
