class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int, int>val_count;
        vector<int>ret;
        for(int i = 0; i < k; ++i) {
            ++val_count[nums[i]];
        }
        ret.push_back((--val_count.end())->first);
        for(int i = 0, j = k; j < nums.size(); ++i, ++j) {
            --val_count[nums[i]];
            if(val_count[nums[i]] == 0) {
                val_count.erase(nums[i]);
            }
            ++val_count[nums[j]];
            ret.push_back((--val_count.end())->first);
        }
        return ret;
    }
};

static auto s = ios_base::sync_with_stdio(false);
static auto ss = cin.tie(nullptr);
static auto sss = cout.tie(nullptr);