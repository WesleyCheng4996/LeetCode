class Solution {
public:
    int minimumLength(string s) {
        string::iterator b = s.begin(), e = s.end() - 1;
        while (b < e && *b == *e) {
            while (b < e && *(++b) == *e);
            while (b < e && *(--e) == *(b - 1));
        };
        return e - b > 0 ? e - b + 1 : *(b - 1) != *b;
    }
};