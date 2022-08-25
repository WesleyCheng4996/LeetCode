class Solution {
public:
    bool isPowerOfThree(int n) {
        return n == 1 ||(n > 1 && fmod(log10(n) / log10(3), 1) == 0);
    }
};