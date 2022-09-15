class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(), changed.end());
        vector<int> ret;
        unordered_map<int, int>mp;
        set<int> st(changed.begin(), changed.end());
        ret.reserve(changed.size());
        for (int x : changed) {
            ++mp[x];
        }
        
        if(st.count(0) == 1 ) {
            if((mp[0] & 1) == 1) {
                return vector<int>();
            } else {
                ret.insert(ret.end(), mp[0] >> 1, 0);
            }
            st.erase(0);
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
