/* Problem url: https://leetcode.com/problems/largest-number
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> sNums;
        for (auto num : nums) {
            if (num) {
                int tmp = num;
                string str = "";
                for (; tmp; tmp /= 10) {
                    str = char(tmp % 10 + '0') + str;
                }
                sNums.push_back(str);
            } else {
                sNums.push_back("0");
            }
        }
        sort(sNums.begin(), sNums.end(), [](string &lhs, string &rhs) {
            return lhs + rhs > rhs + lhs;
        });
        string result = "";
        for (auto str : sNums) {
            result += str;
        }
        while (result.length() > 1 && result[0] == '0') {
            result.erase(0, 1);
        }
        return result;
    }
};

/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: string, sorting
 * 
 * */
