/* Problem url: https://leetcode.com/problems/largest-time-for-given-digits
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        string s = "";
        sort(arr.begin(), arr.end());
        do {
            if (arr[0] * 10 + arr[1] <= 23 && arr[2] * 10 + arr[3] <= 59) {
                s = (char)(arr[0] + '0');
                s += (char)(arr[1] + '0');
                s += ':';
                s += (char)(arr[2] + '0');
                s += (char)(arr[3] + '0');
            }    
        } while (next_permutation(arr.begin(), arr.end()));
        return s;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: string, implementation
 * 
 * */
