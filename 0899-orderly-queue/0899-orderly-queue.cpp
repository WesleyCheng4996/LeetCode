class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k == 1) {
            set<string>st;
            for(int i = 0, end = s.size(); i < end; ++i) {
                st.insert({s.begin() + i, s.end()});
                s.push_back(s[i]);
            }
            s = *st.begin();
        } else {
            sort(s.begin(), s.end());
        }
        return s;
    }
};