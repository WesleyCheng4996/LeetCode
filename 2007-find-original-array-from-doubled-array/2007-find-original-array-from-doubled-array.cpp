class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        unordered_map<int, int>mp;
        vector<int> ret;
        int idx = 0, size = changed.size();
        
        sort(changed.begin(), changed.end());
        mp.reserve(size);
        ret.reserve(size);
        for (int x : changed) {
            ++mp[x];
        }
        
        if(changed[0] == 0) {
            if((mp[0] & 1) == 1) {
                return vector<int>();
            } else {
                ret.insert(ret.end(), mp[0] >> 1, 0);
            }
            do{
                ++idx;
            } while(changed[idx] != 0);
        }
        if(idx == 0) {
            if(mp[changed[0]] > mp[changed[0] << 1]) {
                return vector<int>();
            } else {
                mp[changed[0] << 1] -= mp[changed[0]];
                ret.insert(ret.end(), mp[changed[0]], changed[0]);
            }
            ++idx;
        }
        for (; idx < size; ++idx) {
            if(changed[idx] == changed[idx - 1]) {
                continue;
            }
            if(mp[changed[idx]] > mp[changed[idx] << 1]) {
                return vector<int>();
            } else {
                mp[changed[idx] << 1] -= mp[changed[idx]];
                ret.insert(ret.end(), mp[changed[idx]], changed[idx]);
            }
        }
        return ret;
    }
};

static auto foo = std::ios::sync_with_stdio(false);
static auto fo = std::cin.tie(nullptr);
