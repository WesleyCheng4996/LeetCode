class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int sum = accumulate(begin(nums), end(nums), 0), sum2 = 0;
        int sz = nums.size();
        for(int i = 0; i < sz; ++i) {
            int x = nums[i];
            nums[i] = sum - x * (sz - (i << 1)) - sum2;
            sum2 += x;
            sum -= x;
        }
        return nums;
    }
};