/* Problem url: https://leetcode.com/problems/integer-to-roman
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> table;
        string result = "";
        table.push_back(make_pair(1, "I"));
        table.push_back(make_pair(4, "IV"));
        table.push_back(make_pair(5, "V"));
        table.push_back(make_pair(9, "IX"));
        table.push_back(make_pair(10, "X"));
        table.push_back(make_pair(40, "XL"));
        table.push_back(make_pair(50, "L"));
        table.push_back(make_pair(90, "XC"));
        table.push_back(make_pair(100, "C"));
        table.push_back(make_pair(400, "CD"));
        table.push_back(make_pair(500, "D"));
        table.push_back(make_pair(900, "CM"));
        table.push_back(make_pair(1000, "M"));
        for (int i = table.size() - 1; i >= 0; -- i) {
            while (num >= table[i].first) {
                num -= table[i].first;
                result += table[i].second;
            }
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: 
 * 
 * */
