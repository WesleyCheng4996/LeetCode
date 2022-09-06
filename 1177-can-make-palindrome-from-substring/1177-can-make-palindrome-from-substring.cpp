class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<int*> mp(s.size() + 1);
        for (auto& x : mp) {
            x = new int[26]();
        }
        vector<bool> ans;
        ans.reserve(queries.size());
        for (char x : s) {
            ++mp[0][x - 'a'];
        }
        for (int i = 1, end = s.size(); i < end; ++i) {
            memcpy(mp[i], mp[i - 1], sizeof(int) * 26);
            --mp[i][s[i - 1] - 'a'];
        }
        for (vector<int> vec : queries) {
            ++vec[1];
            int k = 0;
            for (int i = 0; i < 26; ++i) {
                k += (mp[vec[0]][i] - mp[vec[1]][i]) & 1;
            }
            ans.push_back((k >> 1) <= vec[2]);
        }
        return ans;
    }
};