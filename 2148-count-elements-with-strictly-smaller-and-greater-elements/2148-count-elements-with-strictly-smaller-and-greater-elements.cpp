class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return max((int)(lower_bound(nums.begin(), nums.end(), nums.back()) - upper_bound(nums.begin(), nums.end(), nums.front())), 0);
    }
};