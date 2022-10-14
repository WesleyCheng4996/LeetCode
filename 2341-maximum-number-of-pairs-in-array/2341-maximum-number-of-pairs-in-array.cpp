class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int c[101] = { 0 }, ret1 = 0, ret2 = 0;
        for(int x : nums) {
            ++c[x];
        }
        for(int i = 0; i < 101; ++i) {
            ret1 += c[i] >> 1;
            ret2 += c[i] & 1;
        }
        return vector<int>{ ret1, ret2 };
    }
};