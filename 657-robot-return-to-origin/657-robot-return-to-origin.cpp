class Solution {
public:
    bool judgeCircle(string moves) {
        int mp[97] = { 0 };
        for (char ch : moves) ++mp[ch];
        return !((mp['U'] - mp['D']) || (mp['L'] - mp['R']));
    }
};