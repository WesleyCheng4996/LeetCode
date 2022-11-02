class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, ret = INT_MIN;
        for(int i = 0; i < nums.size(); ++i) {
            sum = max(sum + nums[i], nums[i]);
            ret = max(ret, sum);
        }
        return ret;
    }
    int minSubArray(vector<int>& nums) {
        int sum = 0, ret = INT_MAX;
        for(int i = 0; i < nums.size(); ++i) {
            sum = min(sum + nums[i], nums[i]);
            ret = min(ret, sum);
        }
        return ret;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 0) ==  minSubArray(nums) ? maxSubArray(nums) : max(maxSubArray(nums), accumulate(nums.begin(), nums.end(), 0) - minSubArray(nums)) ;
    }
};

static auto s = ios_base::sync_with_stdio(false);
static auto ss = cin.tie(nullptr);
static auto sss = cout.tie(nullptr);