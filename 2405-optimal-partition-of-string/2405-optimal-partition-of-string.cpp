class Solution {
public:
    int partitionString(string s) {
        char *st = new char[26]();
        int ret = 1;
        for(char ch: s) {
            if(st[ch - 'a'] == 1) {
                ++ret;
                st = new char[26]();
            }
            ++st[ch - 'a'];   
        }
        return ret;
    }
};