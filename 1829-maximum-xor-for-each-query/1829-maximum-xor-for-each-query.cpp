class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int target = (1 << maximumBit) - 1;
        vector<int> ans;
        ans.reserve(nums.size());

        for(int i = 0,curr = 0, end = nums.size(); i < end; ++i) {
            curr ^= nums[i];
            ans.push_back(curr ^ target);
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};