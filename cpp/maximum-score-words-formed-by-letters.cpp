/* 
 * Problem url: https://leetcode.com/problems/maximum-score-words-formed-by-letters/
 * Code by ldcduc
 * */

class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size();
        int result = 0;
        for (int state=0; state<1<<n; ++state) {
            int freq[26];
            for (int c=0; c<26; ++c) 
                freq[c] = 0;
            for (int i=0; i<letters.size(); ++i) 
                ++freq[letters[i] - 'a'];
            int cur_result = 0;
            for (int word_idx=0; word_idx<n; ++word_idx)
                if ((state >> word_idx) & 1) {
                    int len = words[word_idx].size(), k = 0, score_ = 0;
                    int d_score = 1, dj = 1, d_freq = -1; // I found this piece of my code is quite interesting
                    for (int j=0; j<len && j>=0; j+=dj)
                        if (freq[words[word_idx][j] - 'a']) {
                            score_ += d_score * score[words[word_idx][j] - 'a'];
                            freq[words[word_idx][j] - 'a'] += d_freq;
                        } else {
                            // It's fun here
                            d_score = 0;
                            score_ = 0;
                            dj = -1;
                            d_freq = 1;
                            //
                        }
                    cur_result += score_;
                }
            if (cur_result > result) 
                result = cur_result;
        }
        return result;
    }
};

/* 
 * Comment by ldcduc
 *
 * */
