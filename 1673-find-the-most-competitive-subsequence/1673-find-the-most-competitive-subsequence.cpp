class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int>ret;
        for(int i = 0; i < nums.size() - k; ++i) {
            while(!ret.empty() && nums[i] < ret.back()) {
                ret.pop_back();
            }
            ret.push_back(nums[i]);
        }
        for(int i = 0; i <= k; ++i) {
            while(ret.size() > i && nums[nums.size() - k + i] < ret.back()) {
                ret.pop_back();
            }
            if(ret.size() < k)
                ret.push_back(nums[nums.size() - k + i]);
        }
        return ret;
    }
};

static auto s = ios_base::sync_with_stdio(false);
static auto ss = cin.tie(nullptr);
static auto sss = cout.tie(nullptr);