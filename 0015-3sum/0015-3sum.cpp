class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>result;
        vector<int>xx(3);

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                int n = nums[i] + nums[j];
                if (binary_search(nums.begin() + j + 1, nums.end(), -n)) {
                    xx[0] = nums[i];
                    xx[1] = nums[j];
                    xx[2] = -n;
                    if(!binary_search(result.begin(), result.end(), xx))
                        result.push_back(xx);
                }
            }
        }

        return result;
    }
};