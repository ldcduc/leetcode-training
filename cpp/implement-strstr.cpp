/* Problem url: https://leetcode.com/problems/implement-strstr
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int getHash(vector<int>&hash, vector<int>& pow, int start, int end, int mod) {
        return (1ll * hash[end] - (start > 0 ? 1ll * hash[start - 1] * pow[end - start + 1] % mod : 0) + 1ll * mod * mod) % mod; 
    }
    int strStr(string haystack, string needle) {
        if (!needle.empty() && haystack.length() >= needle.length()) {
            int mod = 1e9 + 7, needleHash = 0;
            vector<int> hash(haystack.length()), pow(haystack.length() + 1);    
            pow[0] = 1;
            for (int hash_ = 0, i = 0; i < haystack.length(); ++ i) {
                hash_ = (1ll * hash_ * 31 + haystack[i] - 'a') % mod;
                hash[i] = hash_;
                pow[i + 1] = 1ll * pow[i] * 31 % mod;
            }
            int needleLength = needle.length();
            for (int i = 0; i < needleLength; ++ i) {
                needleHash = (1ll * needleHash * 31 + needle[i] - 'a') % mod;
            }
            for (int i = 0; i < haystack.length() - needleLength + 1; ++ i) {
                if (getHash(hash, pow, i, i + needleLength - 1, mod) == needleHash) {
                    return i;
                }
            }
            return -1;
        }    
        return needle.empty() ? 0 : -1;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: hash
 * 
 * */
