class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ret = accumulate(nums.begin(), nums.end(), 0, [](int sum, int x) { return sum ^ x; });
        for(int i = 0, end = nums.size(); i <= end; ++i) {
            ret ^= i;
        }
        return ret;
    }
};