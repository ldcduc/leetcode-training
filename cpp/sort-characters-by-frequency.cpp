/* Problem url: https://leetcode.com/problems/sort-characters-by-frequency
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> M;
        for (int i = 0; i < s.length(); ++ i) {
            ++ M[s[i]];
        }
        vector<pair<int, char>> tmp;
        for (auto item : M) {
            tmp.push_back(make_pair(item.second, item.first));
        }
        sort(tmp.begin(), tmp.end());
        string result = "";
        for (int i = tmp.size() - 1; i >= 0; -- i) {
            for (int j = 0; j < tmp[i].first; ++ j) {
                result += tmp[i].second;
            }    
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: sorting, string
 * 
 * */
