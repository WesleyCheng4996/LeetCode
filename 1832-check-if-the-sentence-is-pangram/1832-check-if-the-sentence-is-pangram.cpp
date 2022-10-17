class Solution {
public:
    bool checkIfPangram(string s) {
        set<int>st;
        for(char c : s) {
            st.insert(c);
        }
        return st.size() == 26;
    }
};