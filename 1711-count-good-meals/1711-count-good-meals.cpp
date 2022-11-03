struct Table {
    int arr[31];
    long long arr2[100005];
    constexpr Table() :
    arr(), arr2()
    {
        for(int i = 0; i < 31; ++i) {
            arr[i] = (1 << i);
        }
        arr2[1] = 1;
        for(int i = 2; i < 100005; ++i) {
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
        vector<int>b(1 << 23, true);
        long long ret = 0;
        for(int x : deliciousness) {
            ++mp[x];
        }
        for(int x : deliciousness) {
            for(int i = 0; x + x >= table.arr[i]; ++i) {
                if(x + x == table.arr[i]) {
                    if(b[x]) {
                        ret += table.arr2[mp[x] - 1];
                        ret %= 1000000007;
                        b[x] = false;
                    } else {
                        continue;
                    }
                } else if(mp.count(table.arr[i] - x)) {
                    ret += mp[table.arr[i] - x];
                    ret %= 1000000007;
                }
            }
        }
        return ret % 1000000007;
    }
};

static auto s = ios_base::sync_with_stdio(false);
static auto ss = cin.tie(nullptr);
static auto sss = cout.tie(nullptr);