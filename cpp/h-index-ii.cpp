/* Problem url: https://leetcode.com/problems/h-index-ii
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int result = 0, l = 0, r = citations.size() - 1;        
        while (l <= r) {
            int m = (l + r) >> 1;
            if (citations.size() - m <= citations[m]) {
                result = citations.size() - m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        } 
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: binary search
 * 
 * */
