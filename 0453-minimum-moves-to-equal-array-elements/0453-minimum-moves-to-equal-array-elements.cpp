class Solution {
public:
    int minMoves(vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 0) - (*min_element(nums.begin(), nums.end()) * nums.size());           
    }
};

static auto s = ios_base::sync_with_stdio(false);
static auto ss = cin.tie(nullptr);
static auto sss = cout.tie(nullptr);