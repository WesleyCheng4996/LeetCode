class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int idx = 0, iidx = 0, ret = 100000000, len = 0, sum = 0, sz = nums.size();
        while(iidx < sz){
            while(iidx < sz && sum < target) {
                sum += nums[iidx++];
            }
            while(idx < sz && sum - nums[idx] >= target) {
                sum -= nums[idx++];
            }
            if(sum >= target)
                ret = min(ret, iidx - idx);
            sum -= nums[idx++];
        }
        return ret == 100000000 ? 0 : ret;
    }
};