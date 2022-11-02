class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int ret = INT_MIN;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() / 2; ++i) {
            ret = max(ret, nums[i] + nums[nums.size() - i - 1]);
        }
        return ret;
    }
};
static auto s = ios_base::sync_with_stdio(false);
static auto ss = cin.tie(nullptr);
static auto sss = cout.tie(nullptr);