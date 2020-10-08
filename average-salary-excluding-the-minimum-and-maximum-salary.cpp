/* Problem url: https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    double average(vector<int>& salary) {
        int maxSal = salary[0], minSal = salary[0], cntMax = 0, cntMin = 0;
        int sum = 0;
        for (auto num : salary) {
            sum += num;
            if (num > maxSal) {
                maxSal = num;
                cntMax = 1;
            } else if (num == maxSal) {
                ++ cntMax;
            }
            if (num < minSal) {
                minSal = num;
                cntMin = 1;
            } else if (num == minSal) {
                ++ cntMin;
            }
        }
        sum -= maxSal * cntMax + minSal * cntMin;
        return 1.0 * sum / (salary.size() - cntMax - cntMin);
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: array
 * 
 * */
