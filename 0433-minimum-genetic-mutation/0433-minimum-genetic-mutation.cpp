class Solution {
public:
    int dfs(string curr, const string& target, int level, const vector<string>& bank, vector<bool>visited) {
        if(curr == target) {
            return level;
        }
        int ret = INT_MAX;
        for(int i = 0; i < visited.size(); ++i) {
            if(visited[i]) {
                continue;
            }
            int diff = 0;
            for(int j = 0; j < 8; ++j) {
                if(curr[j] != bank[i][j]) {
                    ++diff;
                }
            }
            if(diff == 1) {
               visited[i] = true;
                ret = min(ret, dfs(bank[i], target, level + 1, bank, visited));
            }
        }
        return ret;
    }
    int minMutation(string start, string end, vector<string>& bank) {
        int ret = dfs(start, end, 0, bank, vector<bool>(bank.size(), false));
        return ret == INT_MAX ? -1 : ret;
    }
};