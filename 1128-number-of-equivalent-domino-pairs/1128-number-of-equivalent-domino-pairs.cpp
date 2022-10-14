class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& d) {
        map<int, int> mp;
        int ret = 0;
        for(vector<int> &x : d) {
            if(x[0] > x[1]) {
                swap(x[0], x[1]);
            }
            ret += mp[x[0] * 10 + x[1]]++;
        }
        return ret;
    }
};

static auto s = ios_base::sync_with_stdio(false);
static auto ss = cin.tie(nullptr);