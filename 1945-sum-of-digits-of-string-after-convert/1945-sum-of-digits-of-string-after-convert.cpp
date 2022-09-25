class Solution {
public:
    int transform(int num) {
        int ret = 0;
        while (num != 0) {
            ret += num % 10;
            num /= 10;
        }
        return ret;
    }
    int getLucky(string s, int k) {
        int ret = 0;
        for (char ch : s) {
            int i = ch - 'a' + 1;
            ret += i % 10 + i / 10;
        }
        for (int i = 1; i < k; ++i) {
            ret = transform(ret);
        }
        return ret;
    }
};