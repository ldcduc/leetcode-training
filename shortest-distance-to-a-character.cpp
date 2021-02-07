/* Problem url: https://leetcode.com/problems/shortest-distance-to-a-character
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> c_appearance;
        for (int i = 0; i < s.length(); ++ i) {
            if (s[i] == c) {
                c_appearance.push_back(i);
            }
        }
        vector<int> answer(s.length(), 0);
        for (int ci = 1; ci < c_appearance.size(); ++ ci) {
            int fi = c_appearance[ci - 1], se = c_appearance[ci];
            for (int i = fi + 1; i < se; ++ i) {
                answer[i] = min(i - fi, se - i);
            }
        }
        for (int i = 0; i < c_appearance[0]; ++ i) {
            answer[i] = c_appearance[0] - i; 
        }
        for (int i = c_appearance.back() + 1; i < s.length(); ++ i) {
            answer[i] = i - c_appearance.back();
        }
        return answer;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: array
 * 
 * */
