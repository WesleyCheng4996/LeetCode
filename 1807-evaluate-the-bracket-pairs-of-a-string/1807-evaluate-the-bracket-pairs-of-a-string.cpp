class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string>mp;
        string ret = "", key;
        mp.reserve(knowledge.size());
        for(vector<string>& vec : knowledge) {
            mp[vec[0]] = vec[1];
        }
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '(') {
                key = "";
                while(++i < s.size() && s[i] != ')') {
                    key.push_back(s[i]);
                }
                if(mp.count(key)) {
                    ret += mp[key];
                } else {
                    ret.push_back('?');
                }
            } else {
             ret.push_back(s[i]);   
            }
        }
        return ret;
    }
};

static auto s = ios_base::sync_with_stdio(false);
static auto ss = cin.tie(nullptr);
static auto sss = cout.tie(nullptr);