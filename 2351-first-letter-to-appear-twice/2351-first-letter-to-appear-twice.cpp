class Solution {
public:
    char repeatedCharacter(string s) {
        bitset<128>st;
        for(char c : s) {
            if(st[c]) {
                return c;
            }
            st[c] = true;
        }
        return '0';
    }
};