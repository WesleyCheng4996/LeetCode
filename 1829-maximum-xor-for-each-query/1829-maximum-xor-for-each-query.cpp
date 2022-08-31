class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = size(nums);
        int m = (1 << maximumBit) - 1;
        
        vector<int> res;
        res.reserve(n);
        
        for (int i = 0, curr_xor = 0; i < n; i++) {
            curr_xor ^= nums[i];
            res.push_back(m ^ curr_xor);
        }
        
        reverse(begin(res), end(res));
        return res;
    }
};