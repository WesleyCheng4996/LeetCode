class Solution {
public:
    string intToRoman(int num) {
        string ret = "";
        string rett = "";
        int c = num % 10;
        num /= 10;
        if(c >= 5) {
            if(c == 9) {
                ret += "IX";
            } else {
                ret.push_back('V');
                for(int i = 5; i < c; ++i) {
                    ret.push_back('I');
                }
            }
        } else {
            if(c == 4) {
                ret += "IV";
            } else {
                for(int i = 0; i < c; ++i) {
                    ret.push_back('I');
                }
            }
        }
        rett = ret + rett;
        
        ret = "";
        c = num % 10;
        num /= 10;
        if(c >= 5) {
            if(c == 9) {
                ret += "XC";
            } else {
                ret.push_back('L');
                for(int i = 5; i < c; ++i) {
                    ret.push_back('X');
                }
            }
        } else {
            if(c == 4) {
                ret += "XL";
            } else {
                for(int i = 0; i < c; ++i) {
                    ret.push_back('X');
                }
            }
        }
        rett = ret + rett;

        ret = "";
        c = num % 10;
        num /= 10;
        if(c >= 5) {
            if(c == 9) {
                ret += "CM";
            } else {
                ret.push_back('D');
                for(int i = 5; i < c; ++i) {
                    ret.push_back('C');
                }
            }
        } else {
            if(c == 4) {
                ret += "CD";
            } else {
                for(int i = 0; i < c; ++i) {
                    ret.push_back('C');
                }
            }
        }
        rett = ret + rett;

        ret = "";
        c = num % 10;
        num /= 10;
        for(int i = 0; i < c; ++i) {
            ret.push_back('M');
        }
        rett = ret + rett;

        
        return rett;
    }
};