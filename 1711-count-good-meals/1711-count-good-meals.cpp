struct Table {
    int power_2[31];
    unsigned int arr2[100000];
    constexpr Table() :
    power_2(), arr2()
    {
        for(int i = 0; i < 31; ++i) {
            power_2[i] = (1 << i);
        }
        arr2[1] = 1;
        for(int i = 2; i < 100000; ++i) {
            arr2[i] = arr2[i - 1] + i;
            arr2[i] %= 1000000007;
        }
    }
};

constexpr Table table;

class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        unordered_map<int, int>mp;
        vector<int>b(33, true);
        unsigned int ret = 0;
        for(int x : deliciousness) {
            ++mp[x];
        }
        for(int x : deliciousness) {
            for(int i = 0; x + x >= table.power_2[i]; ++i) {
                if(x + x == table.power_2[i]) {
                    if(b[__builtin_clz(x)]) {
                        ret += table.arr2[mp[x] - 1];
                        b[__builtin_clz(x)] = false;
                    } else {
                        continue;
                    }
                } else if(mp.count(table.power_2[i] - x)) {
                    ret += mp[table.power_2[i] - x];
                }
            }
        }
        return ret % 1000000007;
    }
};

static auto s = ios_base::sync_with_stdio(false);
static auto ss = cin.tie(nullptr);
static auto sss = cout.tie(nullptr);