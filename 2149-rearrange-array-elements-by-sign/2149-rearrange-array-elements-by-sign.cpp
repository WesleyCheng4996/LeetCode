class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int sign[] = { 1, 0 };
        for(int i = 0, end = nums.size(); i < end; ++i) {
            ans[sign[nums[i] > 0]] = nums[i];
            sign[nums[i] > 0] += 2;
        }
        return ans;
    }
};