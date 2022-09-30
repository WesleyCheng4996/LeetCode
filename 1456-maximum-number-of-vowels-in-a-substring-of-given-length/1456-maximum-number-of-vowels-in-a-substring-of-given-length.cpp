class Solution {
public:
    int maxVowels(string s, int k) {
        int ret = 0, len = 0, val[128] = { 0 };
        val['a'] = val['e'] = val['i'] = val['o'] = val['u'] = 1;
        len = accumulate(s.begin(), s.begin() + k, 0, [&](int sum, int ch){return sum + val[ch];});
        for(string::iterator it = s.begin(), itt = s.begin() + k; itt < s.end(); ++it, ++itt) {
            if(val[*it] ^ val[*itt]) {
                if(val[*it]) {
                    if(ret < len) {
                        ret = len;
                    }
                    --len;
                } else {
                    ++len;
                }
            }
        }
        return max(len, ret);
    }
};