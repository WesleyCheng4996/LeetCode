class Solution {
public:
    int arraySign(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        nums.push_back(INT_MAX);
        vector<int>::iterator it = lower_bound(nums.begin(), nums.end(), 0);
        return (*it == 0 ? 0 : pow(-1, it - nums.begin()));
    }
};