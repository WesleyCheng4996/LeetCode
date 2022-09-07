class Solution {
public:
    int bitwiseComplement(int n) {
        int x = ~n;
        for(int i = 31; i >= 0; --i) {
            if(x & (1 << i)) {
                x &= ~(1 << i);
            }
            else {
                return x;
            }
        }
        return 1;
    }
};