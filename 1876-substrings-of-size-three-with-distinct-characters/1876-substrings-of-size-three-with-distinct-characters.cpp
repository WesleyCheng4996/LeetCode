class Solution {
public:
    int countGoodSubstrings(string s) {
        int ret = 0;
        for(int i = 1, end = s.size() - 1; i < end; ++i) {
            ret += (s[i] != s[i - 1] && s[i - 1] != s[i + 1] && s[i + 1] != s[i]);
        }
        return ret;
    }
};