class Solution {
public:
    string removeStars(string s) {
        string ret = "";
        ret.reserve(s.size());
        for(char ch : s) {
            if(ch == '*') {
                ret.pop_back();
            } else {
                ret += ch;
            }
        }
        return ret;
    }
};