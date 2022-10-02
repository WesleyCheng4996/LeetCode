class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ret(encoded.size() + 1);
        int idx = -1;
        ret[++idx] = first;
        for(int x : encoded) {
            ret[++idx] = (ret[idx] ^ x);
        }
        return ret;
    }
};