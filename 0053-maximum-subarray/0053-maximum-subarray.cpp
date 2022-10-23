class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int idx1 = 0, idx2 = 0, sum = 0, ret = INT_MIN;
        while(idx2 < nums.size()) {
            while(idx2 < nums.size() && sum >= 0) {
                sum += nums[idx2++];
                ret = max(ret, sum);
            }
            sum = 0;
        }
        return ret;
    }
};