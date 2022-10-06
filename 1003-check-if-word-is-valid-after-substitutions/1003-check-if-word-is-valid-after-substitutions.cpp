class Solution {
public:
    bool isValid(string str) {
        const regex reg("abc");
        const string s = "";
        int sz = 0;
        while(sz != str.size()) {
            sz = str.size();
            str = regex_replace(str, reg, s);
        }
        return str.empty();
    }
};