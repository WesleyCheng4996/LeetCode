class Solution {
public:
    bool reorderedPowerOf2(int num) {
        int c = 0;
        while(num != 0){
            c += 1 << (num % 10);
            num /= 10;
        }
        for (unsigned long long i = 1; i <= 0x80000000; i <<= 1) {
        unsigned long long n = i, m = 0;
        while (n != 0) {
            m += 1 << (n % 10);
            n /= 10;
        }
        if (c == m) {
            return true;
        }
    }
        return false;
    }
};