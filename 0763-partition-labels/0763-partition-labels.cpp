class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<pair<int, int>>mp(26, {-1, -1});
        vector<int>ret;
        stack<int>stk;
        int len = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(mp[s[i] - 'a'].first == -1) {
                mp[s[i] - 'a'].first = i;
                mp[s[i] - 'a'].second = i;
            } else {
                mp[s[i] - 'a'].second = i;
            }
        }
        sort(mp.begin(), mp.end());
        for(pair<int, int>p : mp) {
            if(p.first == -1) {
                continue;
            }
            while(!stk.empty() && p.first > stk.top()) {
               stk.pop();
            }
            if(stk.empty()) {
                ret.push_back(p.first - len);
                len = p.first;
            }
            stk.push(p.second);
        }
        ret.push_back(s.size() - len);
        ret.erase(ret.begin());
        return ret;
    }
};