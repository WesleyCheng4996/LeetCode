class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(int i = 1, end = nums.size(); i < end; ++i){
            nums[i] += nums[i - 1];
        }
        return nums;
    }
};