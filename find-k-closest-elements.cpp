/* Problem url: https://leetcode.com/problems/find-k-closest-elements
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
        for (int i = 0; i < arr.size(); ++ i) {
            Q.push(make_pair(abs(arr[i] - x), arr[i]));
        }    
        vector<int> result;
        for (int i = 0; i < k; ++ i) {
            result.push_back(Q.top().second);
            Q.pop(); 
        }
        sort(result.begin(), result.end());
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: heap, binary search
 * 
 * */
