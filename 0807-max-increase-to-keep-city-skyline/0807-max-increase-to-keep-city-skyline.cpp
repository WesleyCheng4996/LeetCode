class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int* rowsmax = new int[grid.size()]();
        int* colsmax = new int[grid[0].size()]();
        int ret = 0;
        for(int i = 0; i < grid.size(); ++i) {
            int rowmax = grid[i][0];
            for(int j = 0; j < grid[0].size(); ++j) {
                if(rowmax < grid[i][j]) {
                    rowmax = grid[i][j];
                }
                if(colsmax[j] < grid[i][j]) {
                    colsmax[j] = grid[i][j];
                }
            }
            rowsmax[i] = rowmax;
        }
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                ret += min(rowsmax[i], colsmax[j]) - grid[i][j];
            }
        }
        return ret;
    }
};

static auto s = ios_base::sync_with_stdio(false);
static auto ss = cin.tie(nullptr);
static auto sss = cout.tie(nullptr);