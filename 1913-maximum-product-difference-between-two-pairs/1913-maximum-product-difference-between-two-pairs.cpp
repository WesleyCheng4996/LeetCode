class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums.back() * *(nums.end() - 2) - nums[1] * nums[0];
    }
};