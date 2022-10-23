class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>>work;
        int ret = 0;
        for(int i = 0; i < difficulty.size(); ++i) {
            work.push_back({difficulty[i], profit[i]});
        }
        sort(work.begin(), work.end());
        for(int i = 1; i < work.size(); ++i) {
            if(work[i].second < work[i - 1].second) {
                work[i].second = work[i - 1].second;
            }
        }
        work.insert(work.begin(), {0, 0});
        for(int x : worker) {
            ret += (upper_bound(work.begin(), work.end(), pair<int, int>{x, INT_MAX}) - 1)->second;
        }
        return ret;
    }
};

static auto s = ios_base::sync_with_stdio(false);
static auto ss = cin.tie(nullptr);
static auto sss = cout.tie(nullptr);