class Solution {
public:
    int DFS(int currId, unordered_map<int, vector<int>>& manager, vector<int>& informTime) {
        if (manager.count(currId) == 0) {
            return 0;
        }
        int ret = 0;
        for (int subordinate : manager[currId]) {
            ret = max(ret, DFS(subordinate, manager, informTime));
        }
        return ret + informTime[currId];
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>>mp;
        for (int i = 0; i < n; ++i) {
            mp[manager[i]].push_back(i);
        }
        return DFS(headID, mp, informTime);
    }
};

static auto s = ios_base::sync_with_stdio(false);
static auto ss = cin.tie(nullptr);
static auto sss = cout.tie(nullptr);