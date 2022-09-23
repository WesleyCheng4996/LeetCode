class Solution {
public:
    int concatenatedBinary(int n) {
        unsigned long long ret = 0;
        const unsigned int mod = pow(10, 9) + 7;
        for(int i = 1; i <= n; ++i) {
            ret <<= (32 - __builtin_clz(i));
            ret += i;
            if(ret >= mod)
                ret %= mod;
        }
        return (ret);
    }

};