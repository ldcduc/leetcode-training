/* Problem url: https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());    
        vector<pair<int, int>> tmp;
        int prev, hasPrev = false, cnt = 0;
        for (auto num : arr) {
            if (hasPrev) {
                if (prev == num) {
                    ++ cnt;
                } else {
                    tmp.push_back(make_pair(cnt, prev));
                    cnt = 1;
                    prev = num;
                }
            } else {
                cnt = 1;
                prev = num;
                hasPrev = true;
            }
        }
        tmp.push_back(make_pair(cnt, prev));
        sort(tmp.begin(), tmp.end());
        int result = 0;
        for (int i = 0; i < tmp.size(); ++ i) {
            int t = min(k, tmp[i].first);
            k -= t;
            tmp[i].first -= t;
            if (k == 0) {
                result += tmp[i].first > 0;
            }
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: array, sorting
 * 
 * */
