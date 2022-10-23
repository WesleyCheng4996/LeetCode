class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int idx2 = 0, sum = 0, ret = INT_MIN;
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if(sum <= nums[i]) {
                sum = nums[i];
            }
            ret = max(ret, sum);

        }
        return ret;
    }
};