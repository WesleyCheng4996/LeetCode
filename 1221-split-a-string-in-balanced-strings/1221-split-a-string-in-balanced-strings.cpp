class Solution {
public:
    int balancedStringSplit(string s) {
        int ret = 0, record = 0;
        for(char c : s) {
            record += c == 'R' ? 1 : -1;
            ret += record == 0 ? 1 : 0;
        }
        return ret;
    }
};