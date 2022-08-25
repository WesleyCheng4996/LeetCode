class Solution {
public:
    bool isPowerOfFour(int n) {
        return (n & 0b001010101010101010101010101010101) && __builtin_popcount(n) == 1;
    }
};