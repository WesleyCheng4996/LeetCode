class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string>mp;
        string ret = "";
        for(vector<string>& vec : knowledge) {
            mp[vec[0]] = vec[1];
        }
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '(') {
                ++i;
                int j = 0;
                while(i + j < s.size() && s[i + j] != ')') {
                    ++j;
                }
                string key = s.substr(i, j);
                if(mp.count(key)) {
                    ret += mp[key];
                } else {
                    ret.push_back('?');
                }
                i += j;
            } else {
             ret.push_back(s[i]);   
            }
        }
        return regex_replace(ret, regex("\\([a-z]*\\)"), "?");;
    }
};