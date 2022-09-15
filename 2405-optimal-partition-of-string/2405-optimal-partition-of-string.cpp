class Solution {
public:
    int partitionString(string s) {
        int num = 0;
        int ret = 1;
        for(char ch: s) {
            if(num & (1 << (ch - 'a'))) {
                ++ret;
                num = 0;
            }
            num |= (1 << (ch - 'a'));
        }
        return ret;
    }
};

