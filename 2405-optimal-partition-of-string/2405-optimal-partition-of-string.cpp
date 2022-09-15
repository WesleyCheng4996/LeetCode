class Solution {
public:
    int partitionString(string s) {
        unordered_set<char>st;
        int ret = 1;
        for(char ch: s) {
            if(st.count(ch) == 1) {
                ++ret;
                st.clear();
            }
            st.insert(ch);   
        }
        return ret;
    }
};