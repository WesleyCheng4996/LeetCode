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
        unordered_map<int, long long>mp;
        vector<int>b(1 << 23, true);
        double ret = 0;
        for(int x : deliciousness) {
            ++mp[x];
        }
        if(mp.size() > 1) {
        for(int x : deliciousness) {
            for(int i = 0; i < 23; ++i) {
                if(x + x == table.arr[i]) {
                    if(b[x]) {
                        ret += (table.arr2[mp[x] - 1] << 1);
                        b[x] = false;
                    } else {
                        continue;
                    }
                } else if(mp.count(table.arr[i] - x)) {
                    ret += (mp[table.arr[i] - x]);
                }
            }
        }
        return fmod(ret / 2, 1000000007.0);
        } else {
            return table.arr2[mp.begin()->second - 1]; 
        }
    }
};