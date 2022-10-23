class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ret = 0, idx2 = 0, sum = 0;
        while(idx2 < nums.size()) {
            sum += nums[idx2++];
            while(idx2 < nums.size() && nums[idx2] > nums[idx2 - 1]) {
                sum += nums[idx2++];
            }
            ret = max(ret, sum);
            sum = 0;
        }
        return ret;
    }
};