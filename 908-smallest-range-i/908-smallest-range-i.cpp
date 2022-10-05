class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int ma = nums[0], mi = nums[0];
        for(int x : nums) {
            ma = max(ma, x);
            mi = min(mi, x);
        }
        return ((ma - mi) >= (k << 1) ? (ma - mi) - (k << 1) : 0);
    }
};