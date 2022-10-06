class Solution {
public:
    bool isValid(string str) {
        int sz = 0;
        while(sz != str.size()) {
            sz = str.size();
            str = regex_replace(str, regex("abc"), "");
        }
        return str.empty();
    }
};