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
        map<vector<int>, int> mp;
        int ret = 0;
        for(vector<int> &x : d) {
            if(x[0] > x[1]) {
                swap(x[0], x[1]);
            }
            ++mp[x];
        }
        for(auto&[key, val] : mp) {
            ret += t.arr[val];
        }
        return ret;
    }
};