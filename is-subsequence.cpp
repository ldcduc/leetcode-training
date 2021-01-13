/* Problem url: https://leetcode.com/problems/is-subsequence
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int  m =s.length() , n=t.length();
        if(m>n) return 0;
        //string temp;
        int i=0,j=0;
        while(i<m && j<n) {
            if(s[i] == t[j]) {
           //     temp += s[i];
                i++;
                j++;
            }
            else 
                j++;
        }
        return i==m;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: 
 * 
 * */
