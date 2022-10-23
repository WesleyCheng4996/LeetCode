class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k == 1) {
            set<string>st;
            st.insert(s);
            for(int i = 0; i < s.size(); ++i) {
                s.push_back(s[0]);
                s.erase(s.begin());
                st.insert(s);
            }
            s = *st.begin();
        } else {
            sort(s.begin(), s.end());
        }
        return s;
    }
};