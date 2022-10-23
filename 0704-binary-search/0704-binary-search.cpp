class Solution {
public:
    int search(vector<int>& nums, int target) {
        nums.push_back(INT_MAX);
        vector<int>::iterator it = lower_bound(nums.begin(), nums.end(), target);
        return (*it == target ? it - nums.begin() : -1);
    }
};