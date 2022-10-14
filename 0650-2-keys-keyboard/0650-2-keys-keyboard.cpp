class Solution {
public:
    int minSteps(int n) {
        int ret = 0, len = 1, part = 0;
        while(len != n) {
            if(n % len == 0) {
                ++ret;
                part = len;
            }
            ++ret;
            len += part;
        }
        return ret;
    }
};