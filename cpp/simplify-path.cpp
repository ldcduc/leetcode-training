/* Problem url: https://leetcode.com/problems/simplify-path
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    string simplifyPath(string path) {
        deque<string> Q;
        path += '/';
        string tmp = "";
        for (int i = 0; i < path.size(); ++ i) {
            if (path[i] == '/') {
                if (tmp != "") {
                    if (tmp == "..") { // go back to parent directory
                        if (!Q.empty()) {
                            Q.pop_back();
                        }
                    } else if (tmp != ".") { 
                        Q.push_back(tmp);
                    } // else tmp == "." -> do nothing
                }
                tmp = "";
            } else {
                tmp += path[i]; 
            }
        }
        string result = "";
        if (Q.empty()) {
            result = "/";
        } else {
            while (!Q.empty()) {
                tmp = Q.front();
                Q.pop_front();
                result += "/" + tmp;
            }
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: stack
 * 
 * */
