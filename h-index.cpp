/* Problem url: https://leetcode.com/problems/h-index
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int result = 0;
        sort(citations.begin(), citations.end());
        for (int i = 0; i < citations.size(); ++ i) {
            if (citations.size() - i <= citations[i] && citations.size() - i > result) {
                result = citations.size() - i;
            }
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: sorting
 * 
 * */
