class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int, vector<int>>mp;
        int ret = 0;
        for(int i = 0, end = nums.size(); i < end; ++i) {
            mp[nums[i]].push_back(i);
        }
        for(auto x: mp) {
            for(int i = 0, end = x.second.size(); i < end; ++i) {
                for(int j = i + 1; j < end; ++j) {
                    if((x.second[i] * x.second[j]) % k == 0) {
                        ++ret;
                    }
                }
            }
        }
        return ret;
    }
};