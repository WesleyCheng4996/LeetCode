class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<bool>ret(51, false);
        for(vector<int>& vec : ranges) {
            for(int i = vec[0]; i <= vec[1]; ++i) {
                ret[i] = true;
            }
        }
        return all_of(ret.begin() + left, ret.begin() + right + 1, [](bool b) { return b; });
    }
};