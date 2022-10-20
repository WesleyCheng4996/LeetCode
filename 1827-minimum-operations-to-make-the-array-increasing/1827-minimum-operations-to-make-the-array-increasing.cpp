class Solution {
public:
    int minOperations(vector<int>& nums) {
        int high = nums[0] + 1, ret = 0;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] > high) {
                high = nums[i] + 1;
            } else {
                ret += high++ - nums[i];
            }
        }
        return ret;
    }
};