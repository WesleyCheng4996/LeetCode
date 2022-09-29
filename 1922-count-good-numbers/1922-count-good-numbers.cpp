#define mod (1000000007)

struct Pow{
    unsigned long long pow_4[64];
    unsigned long long pow_5[64];
    
    constexpr Pow() :
    pow_4(), pow_5() {
        pow_4[0] = 4;
        pow_5[0] = 5;
        for(int i = 1; i < 64; ++i) {
            pow_4[i] = (pow_4[i - 1] * pow_4[i - 1]) % mod;
            pow_5[i] = (pow_5[i - 1] * pow_5[i - 1]) % mod;
        }
    }
};

constexpr Pow p;

class Solution {
public:
    int countGoodNumbers(long long n) {
        unsigned long long num = (n >> 1), ret = n & 1 ? 5 : 1;
        int bit = 0;
        while(num != 0) {
            if(num & 1) {
                ret *= p.pow_4[bit];
                ret %= mod;
                ret *= p.pow_5[bit];
                ret %= mod;
            }
            num >>= 1;
            ++bit;
        }
        return ret;
    }
};