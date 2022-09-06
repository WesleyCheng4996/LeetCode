class Solution {
public:
    string replaceDigits(string s) {
        const char* s_c = s.c_str();
        for(int i = 1, end = s.size(); i < end; i += 2) {
            s[i] = s_c[i - 1] + s_c[i] - '0';
        }
        return s;
    }
};