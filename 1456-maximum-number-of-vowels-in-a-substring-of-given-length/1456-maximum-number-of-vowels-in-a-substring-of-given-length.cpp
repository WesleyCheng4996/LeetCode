class Solution {
public:
    int maxVowels(string s, int k) {
        int ret = 0, len = 0, val[128] = { 0 };
        val['a'] = val['e'] = val['i'] = val['o'] = val['u'] = 1;
        for(int i = 0; i < k; ++i) {
            len += val[s[i]];
        }
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