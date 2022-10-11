class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int sum = accumulate(begin(nums), end(nums), 0), sum2 = 0, sz = nums.size();
        for(int i = 0; i < sz; ++i) {
            sum2 += nums[i];
            sum -= nums[i];
            nums[i] = sum - nums[i] * (sz - (i << 1) - 2) - sum2;
        }
        return nums;
    }
};