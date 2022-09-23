class Solution {
public:
    int concatenatedBinary(int n) {
        unsigned long long ret = 0;
        for(int i = 1; i <= n; ++i) {
            ret <<= (32 - __builtin_clz(i));
            ret += i;
            ret %= 1000000007;
        }
        return (ret);
    }

};