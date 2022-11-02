class Solution {
public:
    int dfs(string curr, const string& target, int level, const vector<string>& bank, vector<bool>visited) {
        if(curr == target) {
            return level;
        }
        int ret = -1;
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
                int result = dfs(bank[i], target, level + 1, bank, visited);
                if(result != -1) {
                    if(ret == -1) {
                        ret = result;
                    } else {
                        ret = min(ret, result);
                    }
                }
            }
        }
        return ret;
    }
    int minMutation(string start, string end, vector<string>& bank) {
        return dfs(start, end, 0, bank, vector<bool>(bank.size(), false));
    }
};