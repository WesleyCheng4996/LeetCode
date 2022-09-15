class Solution {
public:
    int partitionString(string s) {
        char *st = new char[128]();
        int ret = 1;
        for(char ch: s) {
            if(st[ch] == 1) {
                ++ret;
                st = new char[128]();
            }
            ++st[ch];   
        }
        return ret;
    }
};