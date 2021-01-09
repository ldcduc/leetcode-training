/* Problem url: https://leetcode.com/problems/word-ladder
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<int>> M;
        for (int i = 0; i < wordList.size(); ++ i) {
            M[wordList[i]] = vector<int> (1, i);
        } 
        if (M.count(beginWord) == 0) {
            wordList.push_back(beginWord);
            M[wordList.back()] = vector<int> (1, wordList.size() - 1);
        }
        for (auto word : wordList) {
            string org_word = word;
            for (int i = 0; i < word.length(); ++ i) {
                char org_char = word[i];
                for (char c = 'a'; c <= 'z'; ++ c) {
                    if (c != org_char) {
                        word[i] = c;
                        if (M.count(word) > 0) {
                            M[org_word].push_back(M[word][0]);
                        }
                    }
                } 
                word[i] = org_char;
            }
        }
        unordered_map<string, int> visited;
        visited[beginWord] = 1;
        queue<string> Q;
        Q.push(beginWord);
        while (!Q.empty()) {
            string word = Q.front(); 
            Q.pop();
            int distance = visited[word];
            if (M.count(word) > 0) {
                for (int i = 1; i < M[word].size(); ++ i) {
                    string next_word = wordList[M[word][i]];
                    if (visited.count(next_word) == 0) {
                        visited[next_word] = distance + 1;
                        Q.push(next_word);
                    }
                }
            }
        }
        return visited.count(endWord) == 0 ? 0 : visited[endWord];
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: 
 * 
 * */
