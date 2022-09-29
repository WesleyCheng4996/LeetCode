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
        for(char c : s) {
            goto* labels[c == '1'];
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

static const auto s = ios::sync_with_stdio(0);
static const auto ss = cin.tie(0);
static const auto sss = cout.tie(0);