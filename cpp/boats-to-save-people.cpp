/* Problem url: https://leetcode.com/problems/boats-to-save-people
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int result = 0;
        int left = 0, right = people.size() - 1; 
        while (left <= right) {
            if (people[left] + people[right] <= limit) {
                ++ result;
                ++ left;
                -- right;
            } else {
                ++ result; 
                -- right;
            }
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: 
 * 
 * */
