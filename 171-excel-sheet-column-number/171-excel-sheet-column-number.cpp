class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ret = 0;
        for(char ch: columnTitle) {
            ret *= 26;
            ret += (ch - 'A' + 1);
        }
        return ret;
    }
};