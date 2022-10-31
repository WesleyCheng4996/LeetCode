class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int, int>val_count;
        vector<int>ret;
        for(int i = 0; i < k; ++i) {
            ++val_count[nums[i]];
        }
        ret.push_back(val_count.rbegin()->first);
        for(int i = k; i < nums.size(); ++i) {
            --val_count[nums[i - k]];
            if(val_count[nums[i - k]] == 0) {
                val_count.erase(nums[i - k]);
            }
            ++val_count[nums[i]];
            ret.push_back(val_count.rbegin()->first);
        }
        return ret;
    }
};

static auto s = ios_base::sync_with_stdio(false);
static auto ss = cin.tie(nullptr);
static auto sss = cout.tie(nullptr);