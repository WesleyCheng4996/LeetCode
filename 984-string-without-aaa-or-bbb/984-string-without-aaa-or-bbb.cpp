class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string ret;
        while(a && b) {
            if(a > b) {
                ret += "aab";
                a -= 2, --b;
            } else if(b > a) {
                ret += "bba";
                b -= 2, --a;
            } else {
                ret += "ab";
                --a, --b;
            }
        }
        while(a--) {
            ret += "a";
        }
        while(b--) {
            ret += "b";
        }
        return ret;
    }
};