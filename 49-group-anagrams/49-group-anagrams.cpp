class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mp;
        vector<vector<string>>ret;
        for(int i = 0, end = strs.size(); i < end; ++i) {
            string str = strs[i];
            sort(str.begin(), str.end());
            mp[str].push_back(strs[i]);
        }
        for(const auto &[str, vec]: mp) {
            ret.push_back(move(vec));
        }
        return ret;
    }
};