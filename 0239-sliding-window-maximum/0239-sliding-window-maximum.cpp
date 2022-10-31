class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int, int>val_count;
        map<int, int>::iterator it;
        vector<int>ret;
        for(int i = 0; i < k; ++i) {
            ++val_count[nums[i]];
        }
        ret.push_back(val_count.rbegin()->first);
        for(int i = k; i < nums.size(); ++i) {
            it = val_count.find(nums[i - k]);
            --(it->second);
            if((it->second) == 0) {
                val_count.erase(it);
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