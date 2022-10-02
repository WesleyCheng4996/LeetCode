class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ret;
        ret.reserve(encoded.size() + 1);
        ret.push_back(first);
        for(int x : encoded) {
            ret.push_back(ret.back() ^ x);
        }
        return ret;
    }
};