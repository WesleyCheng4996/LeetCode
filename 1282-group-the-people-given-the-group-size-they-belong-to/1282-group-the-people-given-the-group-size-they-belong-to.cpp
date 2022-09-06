class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> mp;
        vector<vector<int>> ans;
        for(int i = 0, end = groupSizes.size(); i < end; ++i) {
            mp[groupSizes[i]].push_back(i);
        }
        for(auto x : mp) {
            int slice_size = x.second.size() / x.first;
            for(int i = 0; i < slice_size; ++i) {
                ans.push_back(vector<int>(x.second.begin() + (i * x.first), x.second.begin() + ((i + 1) * x.first)));
            }            
        }
        return ans;
    }
};