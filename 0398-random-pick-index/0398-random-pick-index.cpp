class Solution {
public:
    Solution(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i) {
            num_idxs[nums[i]].push_back(i);
            ++idx[nums[i]];
        }
    }
    
    int pick(int target) {
        if(idx[target] == 0) {
            idx[target] = num_idxs[target].size();
        }
        return num_idxs[target][--idx[target]];
    }
    unordered_map<int, vector<int>>num_idxs;
    unordered_map<int, int>idx;
};

static auto s = ios_base::sync_with_stdio(false);
static auto ss = cin.tie(nullptr);
static auto sss = cout.tie(nullptr);

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */