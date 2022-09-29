class Solution {
public:
    int getSum(int a, int b) {
        unsigned int ret = 0, cin = 0;
        for(int i = 0; i < 32; ++i) {
            ret |= (((a >> i) & 1) ^ ((b >> i) & 1) ^ cin) << i;
            cin = (((a >> i) & 1) & ((b >> i) & 1)) || (((a >> i) & 1) & cin) ||(((b >> i) & 1) & cin);
        }
        return ret;
    }
};