/* Problem url: https://leetcode.com/problems/maximum-number-of-eaten-apples
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q; // rottenDay, numOfApple
        int n = days.size(), day, result = 0;
        for (day = 0; day < n; ++ day) {
            Q.push(make_pair(day + days[day], apples[day]));
            while (!Q.empty()) {
                int rottenDay = Q.top().first, apple = Q.top().second;    
                Q.pop();
                if (rottenDay > day) {
                    -- apple;
                    ++ result;
                    if (apple > 0) {
                        Q.push(make_pair(rottenDay, apple));
                    }
                    break;
                }
            }
        }
        while (!Q.empty()) {
            int rottenDay = Q.top().first, apple = Q.top().second;    
            Q.pop();
            if (rottenDay > day) {
                int appleToEat = min(apple, rottenDay - day);    
                result += appleToEat; 
                day += appleToEat;
            }
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: array, heap
 * 
 * */
