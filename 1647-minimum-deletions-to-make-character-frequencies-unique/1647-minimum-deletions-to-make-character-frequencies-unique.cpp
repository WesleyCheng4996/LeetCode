class Solution {
public:
    int minDeletions(string s) {
        int ctr[26] = { 0 };
        map<int, char>mp;
        for (auto& x : s) {
            ++ctr[x - 'a'];
        }
        int count = 0;
        for (int i = 0; i < 26; ++i) {
            if (ctr[i] == 0) {
                continue;
            }
            if (mp.find(ctr[i]) == mp.end()) {
                mp.insert(pair<int, char>(ctr[i], 'a' + i));
            }
            else {
                ++count;
                for (; mp.find(--ctr[i]) != mp.end(); ++count);
                mp.insert(pair<int, char>((ctr[i] == 0? -1 : ctr[i]), 'a' + i));
            }
        }
        return count;
    }
};