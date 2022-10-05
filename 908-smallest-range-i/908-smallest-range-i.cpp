class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int ma = *max_element(nums.begin(),nums.end());
        int mi = *min_element(nums.begin(),nums.end());
        return ((ma - mi) >= (k << 1) ? (ma - mi) - (k << 1) : 0);
    }
};