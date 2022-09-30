class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ret = 0;
        while(target != 1 && maxDoubles) {
            if(target & 1) {
                ret += 2;
            } else {
                ++ret;
            }
            target >>= 1;
            --maxDoubles;
        }
        ret += target;
        return ret - 1;
    }
};