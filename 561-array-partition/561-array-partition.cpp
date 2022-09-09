class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int ret = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0, end = nums.size(); i < end; i += 2) {
            ret += nums[i];
        }
        return ret;
    }
};