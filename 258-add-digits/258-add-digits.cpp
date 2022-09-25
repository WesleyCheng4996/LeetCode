class Solution {
public:
    int addDigits(int num) {
        int ret = num;
        while(num >= 10) {
            ret = 0;
            while(num > 0) {
                ret += num % 10;
                num /= 10;
            }
            num = ret;
        }
        return ret;
    }
};