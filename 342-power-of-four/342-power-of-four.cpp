class Solution {
public:
    bool isPowerOfFour(int n) {
        return n == 1 || (n & 0b001010101010101010101010101010100) && __builtin_popcount(n) == 1;
    }
};