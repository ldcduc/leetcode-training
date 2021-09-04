/* Problem url: https://leetcode.com/problems/rank-teams-by-votes
 * Code by: ldcduc
 * */
/* Begin of Solution */
vector<vector<int>> f;
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int n = votes[0].size();            
        string result = votes[0];
        f.clear();
        f.resize(26, vector<int> (n, 0));
        for (auto vote : votes) {
            for (int i = 0; i < n; ++ i) {
                ++ f[vote[i] - 'A'][i];
            }
        }
        sort(result.begin(), result.end(), [](const char& a, const char& b) {
            for (int i = 0; i < f[0].size(); ++ i) {
                if (f[a - 'A'][i] != f[b - 'A'][i]) {
                    return f[a - 'A'][i] > f[b - 'A'][i];
                }
            }    
            return a < b;
        });
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: sorting
 * 
 * */
