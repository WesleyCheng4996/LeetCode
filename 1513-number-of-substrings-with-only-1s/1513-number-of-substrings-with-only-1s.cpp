struct Table {
    Table() :
    arr() {
        arr[1] = 1;
        for(int i = 2; i < 100001; ++i) {
            arr[i] = (arr[i - 1] + i) % 1000000007;
        }
    }
    int arr[100001];
};

Table table;

class Solution {
public:
    int numSub(string s) {
        int ret = 0, len = 0;
        for(char ch: s) {
            if(ch == '1') {
                ++len;
            } else {
                ret += table.arr[len];
                ret %= 1000000007;
                len = 0;
            }
        }
        return (ret + table.arr[len]) % 1000000007;
    }
};