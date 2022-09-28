struct Table {
    constexpr Table() :
    arr() {
        arr[1] = 1;
        for(int i = 2; i < 100001; ++i) {
            arr[i] = (arr[i - 1] + i) % 1000000007;
        }
    }
    int arr[100001];
};

constexpr Table table;

class Solution {
public:
    int numSub(string s) {
        static constexpr void* labels[2] = { &&ZERO, &&ONE };
        int ret = 0, len = 0;
        for(int i = 0, end = s.size(); i < end; ++i) {
            goto* labels[s[i] == '1'];
        ONE:
            ++len;
            continue;
        ZERO:
            ret += table.arr[len];
            ret %= 1000000007;
            len = 0;
        }
        return (ret + table.arr[len]) % 1000000007;
    }
};