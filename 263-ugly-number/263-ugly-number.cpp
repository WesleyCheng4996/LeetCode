class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) {
            return false;
        }
        while(n % 5 == 0) n /= 5;
        while(n % 3 == 0) n /= 3;
        return __builtin_popcount(n) == 1;
    }
};