/* Problem url: https://leetcode.com/problems/largest-merge-of-two-strings
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    string largestMerge(string word1, string word2) {
        int id1 = 0, id2 = 0;
        int len1 = word1.length(), len2 = word2.length();    
        string result = "";
        while (id1 < len1 && id2 < len2) {
            int added = false;
            for (int i = 0; id1 + i < len1 && id2 + i < len2; ++ i) {
                if (word1[id1 + i] > word2[id2 + i]) {
                    result += word1[id1 ++ ];
                    added = true;
                    break;
                } else if (word1[id1 + i] < word2[id2 + i]) {
                    result += word2[id2 ++ ];
                    added = true;
                    break;
                }
            }
            if (added == false) {
                if (len1 - id1 > len2 - id2) {
                    result += word1[id1 ++ ];
                } else {
                    result += word2[id2 ++ ];
                }
            }
        } 
        for (int i = id1; i < len1; ++ i) {
            result = result + word1[i];
        }
        for (int i = id2; i < len2; ++ i) {
            result = result + word2[i];
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
