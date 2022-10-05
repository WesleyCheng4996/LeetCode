class Solution {
public:
    int minSubArrayLen(int target, vector<int> nums) {
        unsigned int sz = nums.size();
        vector<int>sum(sz + 1);
        int ret = 1111111111;
        sum[sz] = accumulate(nums.begin(), nums.end(), 0);
        for (int i = sz - 1; i >= 0; --i) {
            sum[i] = sum[i + 1] - nums[i];
        }
        for (vector<int>::iterator it = sum.begin(), end = sum.end(); it < end; ++it) {
            vector<int>::iterator itt = lower_bound(it, end, *it + target);
            if (itt != end) {
                ret = min(ret, int(itt - it));
            }
        }
        return ret == 1111111111 ? 0 : ret;
    }
};