class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        set<int>st; 
        for(int x : nums) {
            st.insert(x);
        }
        return st.size() - st.count(0);
    }
};