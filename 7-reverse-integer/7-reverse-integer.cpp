class Solution {
public:
    int reverse(long long int x) {
        long long ret = 0;
        bool sign = false;
        if(x < 0) {
            x = ~x + 1;
            sign = true;
        }
        while(x) {
            ret *= 10;
            ret += x % 10;
            x /= 10;
        }
        return (ret > INT_MAX? 0 : (sign ? ~ret + 1 : +ret));
    }
};