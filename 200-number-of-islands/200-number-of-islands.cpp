void doNothing(vector<vector<char>>& grid, int m, int n);

void destroyIsland(vector<vector<char>>& grid, int m, int n);

void (*funcs[])(vector<vector<char>>&, int, int) = { &doNothing, &destroyIsland };

void destroyIsland(vector<vector<char>>& grid, int m, int n){
    const int mm = grid.size(), nn = grid[0].size();
    
    --grid[m][n];
    
    if(m > 0) {
        funcs[grid[m - 1][n] - '0'](grid, m - 1, n);
    }
    if(m + 1 < mm) {
        funcs[grid[m + 1][n] - '0'](grid, m + 1, n);
    }
    if(n > 0) {
        funcs[grid[m][n - 1] - '0'](grid, m, n - 1);
    }
    if(n + 1 < nn) {
        funcs[grid[m][n + 1] - '0'](grid, m, n + 1);
    }
    return;
}

void doNothing(vector<vector<char>>& grid, int m, int n) {
    return;
}


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        int count = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) { 
                if(grid[i][j] == '1'){
                    destroyIsland(grid, i, j);
                    ++count;
                }
            }
        }
        return count;
    }
};
