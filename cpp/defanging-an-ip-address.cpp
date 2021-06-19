/* Problem url: https://leetcode.com/problems/defanging-an-ip-address
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    string defangIPaddr(string address) {
        string result = "";
        for (int i = 0; i < address.size(); ++ i) {
            if ('0' <= address[i] && address[i] <= '9') {
                result += address[i];
            } else if (address[i] == '.') {
                result += "[.]";
            }
        } 
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: string
 * 
 * */
