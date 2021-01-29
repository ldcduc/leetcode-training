/* Problem url: https://leetcode.com/problems/smallest-string-with-a-given-numeric-value
 * Code by: ldcduc
 * */
/* Begin of Solution */
class LeftToRightSolution {
public:
    string getSmallestString(int n, int k) {
        string result = "";
        for (int i = 0; i < n; ++ i) {
            if (i < n - 1) {
                for (int c = 1; c <= 26; ++ c) {
                    int remainK = k - c;
                    int remainN = n - i - 1;
                    if (remainN <= remainK && remainK <= remainN * 26) {
                        result += c - 1 + 'a';
                        k -= c;
                        break;
                    }
                }
            } else {
                result += k - 1 + 'a';
            }
        } 
        return result;
    }
};
class RightToLeftSolution {
public:
    string getSmallestString(int n, int k) {
        string result = string(n, ' ');
        for (int i = n - 1; i >= 0; -- i) {
            if (i > 0) {
                for (int c = 26; c >= 1; -- c) {
                    if (i <= k - c && k - c <= i * 26) {
                        result[i] = c - 1 + 'a';
                        k -= c;
                        break;
                    }
                }
            } else {
                result[i] = k - 1 + 'a';
            }
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: string, math
 * 
 * */
