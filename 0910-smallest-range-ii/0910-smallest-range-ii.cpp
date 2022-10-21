class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int mi = nums.front();
        int ma = nums.back();
        int ret = ma - mi;
        for(int i = 0; i < nums.size() - 1; ++i) {
            int h = max((int)ma - k, (int)nums[i] + k);
            int l = min((int)mi + k, (int)nums[i + 1] - k);
            ret = min(ret, (int)h - l);
        }
        return ret;
    }
};