/* Problem url: https://leetcode.com/problems/day-of-the-week
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int leapYear(int year) {
        return (year % 100 == 0 && year % 400 == 0) || (year % 100 && year % 4 == 0);
    }
    string dayOfTheWeek(int day, int month, int year) {
        string result[7] = {"Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday"};
        int dayOfMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int dayCount = 0;
        for (int i = 1971; i < year; ++ i) {
            dayCount += 365 + leapYear(i);
        }
        for (int i = 1; i < month; ++ i) {
            dayCount += dayOfMonth[i - 1] + (i == 2 && leapYear(year));
        }
        dayCount += day;
        dayCount -= 1;
        return result[dayCount % 7];
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: fun
 * 
 * */
