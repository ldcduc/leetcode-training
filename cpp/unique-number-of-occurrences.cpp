/* Problem url: https://leetcode.com/problems/unique-number-of-occurrences
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_map<int, bool> M;
        int lastVal = arr[0], cnt = 0;
        arr.push_back(arr[0]);
        for (auto num : arr) {
            if (num == lastVal) {
                ++ cnt;
            } else {
                if (M.count(cnt)) {
                    return false;
                } 
                M[cnt] = true;
                cnt = 1;
                lastVal = num;
            }   
        }
        return true;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: sorting, hash table
 * 
 * */
