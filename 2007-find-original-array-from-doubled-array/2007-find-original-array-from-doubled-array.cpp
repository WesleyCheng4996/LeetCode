class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> ret;
        unordered_map<int, int>mp;
        sort(changed.begin(), changed.end());
        ret.reserve(changed.size());
        for (int x : changed) {
            ++mp[x];
        }
        for (int x : changed) {
            if (mp[x] == 0) {
                continue;
            }
            --mp[x];
            if (mp.count(x << 1) == 0 || mp[x << 1] == 0) {
                return vector<int>();
            }
            else {
                --mp[x << 1];
            }
            ret.push_back(x);
        }
        return ret;
    }
};

