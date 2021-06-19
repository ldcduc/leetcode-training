/* Problem url: https://leetcode.com/problems/decode-xored-array
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int n = encoded.size() + 1;        
        vector<int> result(n);
        int sum = 0;
        for (int i = 0; i < n - 1; ++ i) {
            sum ^= encoded[i];    
        }
        result[0] = first;
        result[n - 1] = first ^ sum; 
        int prev = first;
        for (int i = 1; i < n - 1; ++ i) {
            result[i] = encoded[i - 1] ^ prev;
            prev = result[i];
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: xor
 * 
 * */
