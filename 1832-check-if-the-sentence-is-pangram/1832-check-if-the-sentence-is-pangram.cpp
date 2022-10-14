class Solution {
public:
    bool checkIfPangram(string s) {
        unordered_set<int>st;
        for(char c : s) {
            st.insert(c);
        }
        return st.size() == 26;
    }
};