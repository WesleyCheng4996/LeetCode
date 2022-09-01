class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        vector<int>copy(nums.begin(), nums.end());
        sort(copy.begin(), copy.end());
        for (int i = 0, end = copy.size(); i < end; ++i) {
            auto x = lower_bound(copy.begin() + i, copy.end(), target - copy[i]);
            if (x != copy.end() && *x == target - copy[i]) {
                result.push_back(find(nums.begin(), nums.end(), copy[i]) - nums.begin());
                if (*x == target - *x) {
                    result.push_back(find(nums.begin() + result[0] + 1, nums.end(), *x) - nums.begin());
                }
                else {
                    result.push_back(find(nums.begin(), nums.end(), *x) - nums.begin());
                }
                break;
            }
        }
        if (result[0] > result[1]) {
            swap(result[0], result[1]);
        }
        return result;
    }
};