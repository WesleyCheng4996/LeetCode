class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idx = 0;
        for(char c : s) {
            int pos = t.substr(idx).find(c);
            if(pos == string::npos) {
                return false;
            }
            idx += pos + 1;
        }
        return true;
    }
};