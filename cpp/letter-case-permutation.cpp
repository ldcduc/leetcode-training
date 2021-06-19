/* Problem url: https://leetcode.com/problems/letter-case-permutation
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> result(1, S);
        int n = S.length();    
        unordered_map<int, int> bitM; // mapping from (1 << i) aka 2^i --> i
        for (int i = 0; i < n; ++ i) {
            bitM[1 << i] = i;
        } 
        for (int state = 0; state < (1 << n); ++ state) {
            string tmp = S;
            int changed = 0; 
            for (int tmpState = state, bit; tmpState; tmpState -= tmpState & -tmpState) {
                bit = bitM[tmpState & -tmpState];    
                if (S[bit] < '0' || S[bit] > '9') {
                    tmp[bit] = tmp[bit] + (tmp[bit] >= 'a' ? -'a' + 'A' : -'A' + 'a');    
                    ++changed;
                } else {
                    changed = 0;
                    break;
                }
            } 
            if (changed) {
                result.push_back(tmp);
            }
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: combination
 * 
 * */
