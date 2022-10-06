class Solution {
public:
    bool isValid(string str) {
        regex reg("abc");
        int sz = 0;
        while(sz != str.size()) {
            sz = str.size();
            str = regex_replace(str, reg, "");
        }
        return str.empty();
    }
};