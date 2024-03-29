class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 0, [](int sum, int x) { return sum ^ x; });
    }
};
static auto s = ios_base::sync_with_stdio(false);
static auto ss = cin.tie(nullptr);