/* Problem url: https://leetcode.com/problems/orderly-queue
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k == 1) {
            string res = s;
            for (int i = 0; i < s.length(); ++ i) {
                string first = s.substr(i + 1, s.length() - i - 1);
                string second = s.substr(0, i + 1);
                string tmp = first + second;
                if (tmp < res) { 
                    res = tmp; 
                }
            }     
            return res;
        }
        sort(s.begin(), s.end());
        return s;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: string
 * 
 * */
