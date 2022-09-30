class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ret(1);
        ret.reserve(10000);
        ret.push_back(nums);
        
        for(int i = 0, end = nums.size(); i < end; ++i) {
            bfs(nums, ret, i);
        }
        return ret;
    }
    void bfs(vector<int> nums, vector<vector<int>> &ret, int idx) {
        if(nums.size() == 1) {
            return;
        }
        nums.erase(nums.begin() + idx);
        for(int i = idx, end = nums.size(); i < end; ++i) {
            bfs(nums, ret, i);
        }
        ret.push_back(nums);
    }
};