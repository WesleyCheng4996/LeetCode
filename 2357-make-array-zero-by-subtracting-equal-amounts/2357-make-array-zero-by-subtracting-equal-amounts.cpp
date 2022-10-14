class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        set<int>st(nums.begin(), nums.end()); 
        return st.size() - st.count(0);
    }
};