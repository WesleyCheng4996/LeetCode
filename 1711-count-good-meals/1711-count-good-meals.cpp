struct Table {
    int power_2[31];
    constexpr Table() :
    power_2()
    {
        for(int i = 0; i < 31; ++i) {
            power_2[i] = (1 << i);
        }
    }

};

constexpr Table table;

class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        unordered_map<int, unsigned int>mp;
        unsigned int ret = 0;
        for(int x : deliciousness) {
            for(int i = 0; i < 22; ++i) {
                if(mp.count(table.power_2[i] - x)) {
                    ret += mp[table.power_2[i] - x];
                    ret %= 1000000007;
                }
            }
            ++mp[x];
        }
        return ret;
    }
};

static auto s = ios_base::sync_with_stdio(false);
static auto ss = cin.tie(nullptr);
static auto sss = cout.tie(nullptr);