class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int max_num = nums[0], ret = 0;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] >= max_num) {
                if(all_of(nums.begin() + i, nums.end(), [&](int num){ return num >= max_num; })) {
                    return i;
                } else {
                    max_num = nums[i];
                }
            }
        }
        return -1;
    }
};

static auto s = ios_base::sync_with_stdio(false);
static auto ss = cin.tie(nullptr);
static auto sss = cout.tie(nullptr);