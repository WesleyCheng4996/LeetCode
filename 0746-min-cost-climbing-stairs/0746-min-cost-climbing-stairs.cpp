class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        for(int i = 2; i < cost.size(); i++) {
            cost[i] += min(cost[i-1], cost[i-2]);
        }
        return min(cost[cost.size() - 1], cost[cost.size() - 2]);//At the end the final answer depends on the last two costs
    }
};

static auto s = ios_base::sync_with_stdio(false);
static auto ss = cin.tie(nullptr);
static auto sss = cout.tie(nullptr);