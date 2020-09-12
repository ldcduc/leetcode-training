/* Problem url: https://leetcode.com/problems/score-of-parentheses
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int scoreOfParentheses(string S) {
        vector<int> openPos;
        vector<pair<int, int>> score;
        int len = S.length();
        for (int i = 0; i < len; ++ i) {
            if (S[i] == '(') {
                score.push_back(make_pair(0, i));
                openPos.push_back(i);
            } else {
                if (openPos.back() == i - 1) {
                    score[score.size() - 1].first = 1;
                } else {
                    int sum = 0;
                    while (openPos.back() != score.back().second) {
                        sum += score.back().first;
                        score.pop_back();
                    }
                    score[score.size() - 1].first = 2 * sum;
                }
                openPos.pop_back();        
            }
        }
        int result = 0;
        while (!score.empty()) {
            result += score.back().first;
            score.pop_back();
        }
        return result; 
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: parentheses type, FIFO
 * 
 * */
