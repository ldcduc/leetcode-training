/* 
 * Problem url: https://leetcode.com/problems/reducing-dishes/
 * Code by: ldcduc
 * */
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int result = 0, sum = 0;
        for (int i=satisfaction.size()-1; i>=0; --i) {
            sum += satisfaction[i];
            if (result + sum > result)
                result = result + sum;
        }
        return result;
    }
};

/* 
 * Comment by ldcduc
 * I find this problem quite fun (at least with my solution)
 * */
