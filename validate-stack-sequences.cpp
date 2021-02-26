/* Problem url: https://leetcode.com/problems/validate-stack-sequences
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int id = 0;
        for (int i = 0; i < pushed.size(); ++ i) {
            s.push(pushed[i]);
            while (id < popped.size() && !s.empty() && s.top() == popped[id]) {
                s.pop();
                ++ id;
            }
        }
        while (id < popped.size() && !s.empty() && s.top() == popped[id]) {
            s.pop();
            ++ id;
        }
        return s.empty() && id == popped.size();
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: stack
 * 
 * */
