/* Problem url: https://leetcode.com/problems/course-schedule-ii
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> Q;
        vector<vector<int>> pre(numCourses);
        vector<int> deg(numCourses, 0);
        for (auto item : prerequisites) {
            ++ deg[item[0]];
            pre[item[1]].push_back(item[0]);
        }
        for (int i = 0; i < numCourses; ++ i) {
            if (deg[i] == 0) {
                Q.push(i);
            }
        }
        int learnedCourses = 0;
        vector<int> result;
        
        int course;
        while (!Q.empty()) {
            course = Q.front();
            Q.pop();
            result.push_back(course);
            ++ learnedCourses;
            for (auto item : pre[course]) {
                -- deg[item];
                if (deg[item] <= 0) {
                    Q.push(item);
                }
            }
        }
        if (learnedCourses < numCourses) {
            result.clear(); 
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: queue
 * 
 * */
