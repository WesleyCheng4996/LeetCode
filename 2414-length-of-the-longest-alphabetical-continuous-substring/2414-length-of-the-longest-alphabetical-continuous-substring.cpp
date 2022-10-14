class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ret = 1, len = 1;
        for(int i = 0; i < s.size(); ++i) {
            int p = i + 1;
            while(p < s.size() && s[p] == s[p - 1] + 1) {
                ++p;
                ++len;
            }
            if(len > ret) {
                ret = len;
            }
            len = 1;
        }
        return ret;
    }
};