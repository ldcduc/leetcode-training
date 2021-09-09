/* Problem url: https://leetcode.com/problems/exam-room
 * Code by: ldcduc
 * */
/* Begin of Solution */
class ExamRoom {
    int N;
    vector<int> students;
public:
    ExamRoom(int n) {
        N = n;
        students.clear();
    }
    
    int seat() {
        if (students.empty()) {
            students.push_back(0);
            return 0;
        } 
        int d = max(students[0], N - 1 - students.back());
        for (int i = 0; i < students.size() - 1; ++ i) {
            d = max(d, (students[i + 1] - students[i]) / 2);
        }
        if (students[0] == d) {
            students.insert(students.begin(), 0);
            return 0;
        }
        for (int i = 0; i < students.size() - 1; ++ i) {
            if ((students[i + 1] - students[i]) / 2 == d) {
                students.insert(students.begin() + i + 1, (students[i + 1] + students[i]) / 2);
                return students[i + 1];
            }
        }
        students.push_back(N - 1);
        return N - 1;
    }
    
    void leave(int p) {
        for (int i = 0; i < students.size(); ++ i) {
            if (students[i] == p) {
                students.erase(students.begin() + i);
            }
        } 
    }
};
/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: array
 * 
 * */
