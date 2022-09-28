class Solution {
public:
    int binaryGap(int n) {
        if(n == 1) {
            return 0;
        }
        int len = 1, ret = 0;
        if ((n & 1) == 0) {
            while (((n >>= 1) & 1) == 0);
            n >>= 1;
        }
        for (; n; n >>= 1) {
            if (n & 1) {
                if (ret < len) {
                    ret = len;
                }
                len = 1;
            }
            else {
                ++len;
            }
        }
    return ret;
    }
};