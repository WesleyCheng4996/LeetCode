class Solution {
public:
    int Map(int num, vector<int>& mapping) {
        if(num == 0) {
            return mapping[0];
        }
        vector<int>digits;
        int ret = 0;
        digits.reserve(10);
        while(num) {
            digits.push_back(num % 10);
            num /= 10;
        }
        for(int i = digits.size() - 1; i >= 0; --i) {
            ret *= 10;
            ret += mapping[digits[i]];
        }
        return ret;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>>vec;
        vector<int>ret;
        vec.reserve(nums.size());
        ret.reserve(nums.size());
        for(int num : nums) {
            vec.push_back({Map(num, mapping), num});
        }
        stable_sort(vec.begin(), vec.end(), [](pair<int, int>p, pair<int, int>pp){return p.first < pp.first;});
        for(auto& [_, val] : vec) {
            ret.push_back(val);
        }
        return ret;
    }
};

static auto s = ios_base::sync_with_stdio(false);
static auto ss = cin.tie(nullptr);
static auto sss = cout.tie(nullptr);