class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int ret = 0;
        special.push_back(bottom - 1);
        special.push_back(top + 1);
        sort(special.begin(), special.end());
        for(int i = 0, end = special.size() - 1; i < end; ++i) {
            int diff = special[i + 1] - special[i];
            if(ret < diff) {
                ret = diff;
            }
        }
        return --ret;
    }
};

static const auto s = ios::sync_with_stdio(0);
static const auto ss = cin.tie(0);
static const auto sss = cout.tie(0);