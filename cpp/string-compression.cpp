/* Problem url: https://leetcode.com/problems/string-compression
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int compress(vector<char>& chars) {
        int result = 0, cnt = 0;
        int index = 0;
        char ch = 'a' - 1;
        for (int i = 0; i < chars.size(); ++ i) {
            if (chars[i] != ch) {
                ch = chars[i];
                if (cnt > 1) {
                    string s = to_string(cnt);
                    for (auto c : s) {
                        chars[index ++] = c;
                    }
                    result += s.length();
                }
                //
                ++ result;
                chars[index ++] = chars[i];
                cnt = 1;
            } else {
                ++ cnt;
            }        
        }    
        if (cnt > 1) {
            string s = to_string(cnt);
            for (auto c : s) {
                chars[index ++] = c;
            }
            result += s.length();
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
