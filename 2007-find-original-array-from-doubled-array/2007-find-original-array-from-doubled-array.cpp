class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> ret;
        unordered_map<int, int>mp;
        sort(changed.begin(), changed.end());
        set<int> st(changed.begin(), changed.end());
        st.erase(0);
        ret.reserve(changed.size());
        for (int x : changed) {
            ++mp[x];
        }
        if((mp[0] & 1) == 1) {
            return vector<int>();
        } else {
            ret.insert(ret.end(), mp[0] >> 1, 0);
        }
        for (int x : st) {
            if(mp[x] > mp[x << 1]) {
                return vector<int>();
            } else {
                mp[x << 1] -= mp[x];
                ret.insert(ret.end(), mp[x], x);
            }
        }
        return ret;
    }
};

static auto foo = std::ios::sync_with_stdio(false);
static auto fo = std::cin.tie(nullptr);
