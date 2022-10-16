class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string comp = "";
        for(int i = 0; i < words.size(); ++i) {
            if(comp.size() >= s.size()) {
                return comp == s;
            } 
            comp += words[i];
        }
        return comp == s;
    }
};