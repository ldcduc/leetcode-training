/* Problem url: https://leetcode.com/problems/corporate-flight-bookings
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> bookingPerFlight(n + 2, 0);
        for (auto booking : bookings) {
            bookingPerFlight[booking[0]] += booking[2];
            bookingPerFlight[booking[1] + 1] -= booking[2];
        }
        vector<int> result;
        for (int i = 1; i <= n; ++i) {
            bookingPerFlight[i] += bookingPerFlight[i - 1];
            result.push_back(bookingPerFlight[i]);
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: fun, tricky
 * 
 * */
