class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string>st;
        for(auto x: paths) {
            st.insert(x[1]);
        }
        for(auto x: paths) {
            st.erase(x[0]);
        }
        return *st.begin();
    }
};