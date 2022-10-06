class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> ret;
        for(char c = s[0]; c <= s[3]; ++c) {
            for(char cc = s[1]; cc <= s[4]; ++cc) {
                ret.push_back(string {c, cc});
            }
        }
        return ret;
    }
};