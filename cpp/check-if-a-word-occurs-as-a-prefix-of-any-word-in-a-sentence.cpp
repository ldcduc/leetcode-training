/* Problem url: https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int start = 0, wordCnt = 0;
        string word = "";
        sentence += ' ';
        for (int i = 0; i < sentence.length(); ++ i) {
            if (sentence[i] != ' ') {
                wordCnt += i == 0 || sentence[i - 1] == ' ';
                word += sentence[i];
            } else                                                  {
                if (i > 0 && sentence[i - 1] != ' ') {
                    if (word.length() >= searchWord.length() && searchWord == word.substr(0, searchWord.length()))    {
                        return wordCnt;
                    }
                }
                word = "";
            }
        }
        return -1;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: string, implementation
 * 
 * */
