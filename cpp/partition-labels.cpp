/* Problem url: https://leetcode.com/problems/partition-labels
 * Code by: ldcduc
 * */
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> result;
        vector<int> pos[26];
        for (int i = 0; i < S.length(); ++ i) {
            pos[S[i] - 'a'].push_back(i);
        }
        int l = 0;
        for (int r = 0; r < S.length(); ++ r) {
            bool check = true;
            for (int c = 0; c < 26; ++ c) {
                if (!pos[c].empty() && pos[c].front() >= l && pos[c].front() <= r && pos[c].back() > r) {
                    check = false;
                }
            }
            if (check) {
                result.push_back(r - l + 1);
                l = r + 1;
            }
        }
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: string, implementation
 * 
 * */

