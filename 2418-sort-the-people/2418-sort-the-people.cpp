class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>>vec;
        vec.reserve(names.size());
        for(int i = 0; i < names.size(); ++i) {
            vec.push_back(pair<int, string>{heights[i], names[i]});
        }
        sort(begin(vec), end(vec));
        vector<string>ret;
        ret.reserve(names.size());
        for(int i = 0; i < names.size(); ++i) {
            ret.push_back(vec[names.size() - i - 1].second);
        }
        return ret;
    }
};