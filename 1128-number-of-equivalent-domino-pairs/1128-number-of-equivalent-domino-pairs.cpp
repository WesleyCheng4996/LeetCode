struct Table{
    int arr[40001];
    constexpr Table() :
    arr()
    {
        for(int i = 1; i < 40000; ++i) {
            arr[i + 1] = arr[i] + i;
        }
    }
};

constexpr Table t;

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& d) {
        map<int, int> mp;
        int ret = 0;
        for(vector<int> &x : d) {
            if(x[0] > x[1]) {
                swap(x[0], x[1]);
            }
            ++mp[x[0] * 10 + x[1]];
        }
        for(auto&[key, val] : mp) {
            ret += t.arr[val];
        }
        return ret;
    }
};

static auto s = ios_base::sync_with_stdio(false);
static auto ss = cin.tie(nullptr);