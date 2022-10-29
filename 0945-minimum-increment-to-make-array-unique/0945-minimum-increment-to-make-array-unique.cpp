class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int ret = 0, curr = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i) {
            if(curr >= nums[i]) {
                ret += curr - nums[i];
                ++curr;
            } else {
                curr = nums[i] + 1;
            }
        }
        return ret;
    }
};

static auto s = ios_base::sync_with_stdio(false);
static auto ss = cin.tie(nullptr);
static auto sss = cout.tie(nullptr);