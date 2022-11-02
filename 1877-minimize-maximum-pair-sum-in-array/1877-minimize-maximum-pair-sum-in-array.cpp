class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int ret = INT_MIN, sz = (nums.size() >> 1);
        sort(nums.begin(), nums.end());
        for(int i = 0; i < sz;) {
            ret = max(ret, nums[i] + nums[nums.size() -  (++i)]);
        }
        return ret;
    }
};
static auto s = ios_base::sync_with_stdio(false);
static auto ss = cin.tie(nullptr);
static auto sss = cout.tie(nullptr);