class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        bool find[1 << 16 + 1] = { false };
        int num = 0, sz = 1 << n;
        ret.reserve(sz);
        ret.push_back(0);
        find[0] = true;
        while (ret.size() < sz) {
            for (int bit = 0; bit < n; ++bit) {
                if (!find[num ^ (1 << bit)]) {
                    ret.push_back(num ^= (1 << bit));
                    find[ret.back()] = true;
                    break;
                }
            }
        }
        return ret;
    }
};