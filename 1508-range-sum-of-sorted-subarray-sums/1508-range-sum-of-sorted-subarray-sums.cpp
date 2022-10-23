class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long>newarr;
        int ret = 0;
        newarr.reserve(n * n);
        for(int i = 0; i < nums.size(); ++i) {
            long long k = 0LL;
            for(int j = i; j < nums.size(); ++j) {
                newarr.push_back(k += nums[j] % 1000000007);
            }
        }
        sort(newarr.begin(), newarr.end());
        --left;
        for(; left < right; ++left) {
            ret += newarr[left];
            ret %= 1000000007;
        }
        return ret % 1000000007;
    }
};