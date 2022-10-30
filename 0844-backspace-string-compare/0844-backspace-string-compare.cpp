class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string rets = "", rett = "";
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '#') {
                if(!rets.empty())
                    rets.pop_back();
            } else {
                rets.push_back(s[i]);
            }
        }
        for(int i = 0; i < t.size(); ++i) {
            if(t[i] == '#') {
                if(!rett.empty())
                    rett.pop_back();
            } else {
                rett.push_back(t[i]);
            }
        }
        return rets == rett;
    }
};