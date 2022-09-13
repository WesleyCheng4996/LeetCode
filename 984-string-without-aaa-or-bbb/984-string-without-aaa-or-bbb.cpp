class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string ret;
        if(a > b){
            while(a > b && a > 0 && b > 0) {
                ret += "aab";
                a -= 2, --b;
            }
            while(a && b ) {
                ret += "ab";
                --a, --b;
            }
            while(a) {
                ret += "a";
                --a;
            }
        } else {
            while(a < b && a > 0 && b > 0) {
                ret += "bba";
                b -= 2, --a;
            }
            while(a && b) {
                ret += "ba";
                --b, --a;
            }
            while(b) {
                ret += "b";
                --b;
            }
        }
        return ret;
    }
};