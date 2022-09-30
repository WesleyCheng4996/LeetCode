class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ret = 0;
        while(target) {
            if(target & 1) {
                --target;
                ++ret;
            } else {
                target >>= 1;
                if(maxDoubles) {
                    ++ret;
                    --maxDoubles;
                } else {
                    ret += target;
                }
            }
        }
        return ret - 1;
    }
};