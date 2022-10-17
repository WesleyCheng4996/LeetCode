class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char table[128] = { 0 };
        for(int i = 0; i < s.size(); ++i) {
            if(table[s[i]] == 0) {
                table[s[i]] = t[i];
            } else {
                if(table[s[i]] != t[i]) {
                    return false;
                }
            }
        }
        unordered_set<char>st;
        for(int i = 0; i < 128; ++i) {
            if(table[i] != 0 && st.count(table[i])) {
                return false;
            }
            st.insert(table[i]);
        }
        return true;
    }
};