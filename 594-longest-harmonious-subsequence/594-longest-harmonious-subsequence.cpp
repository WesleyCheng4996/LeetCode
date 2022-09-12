class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ret = 0;
        for(int x: nums) {
            ++mp[x];
        }
        for(const auto&[idx, count]: mp) {
            if(mp.count(idx + 1)) {
                ret = max(ret, mp[idx] + mp[idx + 1]);
            }
        }
        return ret;
    }
};