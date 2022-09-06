class Solution {
public:
    int minimumLength(string s) {
        string::iterator b = s.begin(), e = s.end() - 1;
        while (b < e && *b == *e) {
            char temp(*b);
            while (b < e && *(++b) == temp);
            while (b < e && *(--e) == temp);
        };
        return e - b > 0 ? e - b + 1 : *(b - 1) != *b;
    }
};