class Solution {
public:
    char findTheDifference(string s, string t) {
        char ret = 0;
        s += t;
        for(char c : s) {
            ret ^= c;
        }
        return ret;
    }
};