class Solution {
public:
    int xorOperation(int n, int start) {
        int ret = 0;
        for(; n--; start += 2) {
            ret ^= start;
        }
        return ret;
    }
};