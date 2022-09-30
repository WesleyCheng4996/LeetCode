class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>st;
        st.push_back(vector<int>{});
        st.push_back(nums);
        
        for(int i = 0, end = nums.size(); i < end; ++i) {
            bfs(nums, st, i);
        }
        vector<vector<int>>ret(st.begin(), st.end());
        return ret;
    }
    void bfs(vector<int> nums, vector<vector<int>> &st, int idx) {
        if(nums.size() == 1) {
            return;
        }
        nums.erase(nums.begin() + idx);
        for(int i = idx, end = nums.size(); i < end; ++i) {
            bfs(nums, st, i);
        }
        st.push_back(nums);
    }
};