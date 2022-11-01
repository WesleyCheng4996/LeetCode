class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<vector<string>> h(11, vector<string>());
        vector<vector<string>> m(11, vector<string>());
        vector<string>ret;
        for(int i = 0; i < 12; ++i) {
            h[__builtin_popcount(i)].push_back(to_string(i));
        }
        for(int j = 0; j < 60; ++j) {
            m[__builtin_popcount(j)].push_back((j < 10 ? "0" : "") + to_string(j));
        }
        for(int i = 0; i <= turnedOn; ++i) {
            for(string hh : h[i]) {
                for(string mm : m[turnedOn - i]) {
                    ret.push_back(hh + ":" + mm);
                }
            }
        }
        return ret;
    }
};