class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size() > s.size()) {
            return vector<int>{};
        }
        vector<int>target(26, 0);
        vector<int>curr(26, 0);
        vector<int>ret;
        int k = p.size();
        for(char c : p) {
            ++target[c - 'a'];
        }
        for(int i = 0; i < k; ++i) {
            ++curr[s[i] - 'a'];
        }
        for(int idx1 = 0, idx2 = k; idx2 < s.size(); ++idx1, ++idx2) {
            if(curr == target) {
                ret.push_back(idx1);
            }
            --curr[s[idx1] - 'a'];
            ++curr[s[idx2] - 'a'];
        }
        if(curr == target) {
            ret.push_back(s.size() - k);
        }
        return ret;
    }
};