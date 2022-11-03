class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ret;
        for(int i = 0; i < s.size();) {
            char c = s[i];
            ret.push_back(vector<int>{i});
            while(i < s.size() && s[++i] == c);
            if(i - ret.back()[0] > 2) {
                ret.back().push_back(i - 1);
            } else {
                ret.pop_back();
            }
        }
        return ret;
    }
};