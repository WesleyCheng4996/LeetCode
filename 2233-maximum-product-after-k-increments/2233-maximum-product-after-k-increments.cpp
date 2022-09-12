class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        const int mod = pow(10, 9) + 7;
        long long ret = 1;
        sort(nums.begin(), nums.end());
        int min = nums.front();
        while(k > 0) {
            ++min;
            for(int i = 0, end = nums.size(); i < end; ++i) {
                if(nums[i] < min) {
                    ++nums[i];
                    --k;
                    if(k == 0) {
                        break;
                    }
                } else {
                    break;
                }
            }
        }
        for(int x: nums) {
            ret *= x;
            ret %= mod;
        }
        return ret;
    }
};