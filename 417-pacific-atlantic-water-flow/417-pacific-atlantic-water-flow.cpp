char checkPass(vector<vector<char>>& pass, int i, int j, bool** passed) {
    if ((pass[i][j] & 0b110000) == 0b110000) {
        return 0b110000;
    }
    passed[i][j] = true;
    if (pass[i][j] & 0b0001000 && !passed[i - 1][j]) {
        pass[i][j] |= checkPass(pass, i - 1, j, passed);
    }
    if (pass[i][j] & 0b0000100 && !passed[i + 1][j]) {
        pass[i][j] |= checkPass(pass, i + 1, j, passed);
    }
    if (pass[i][j] & 0b0000010 && !passed[i][j - 1]) {
        pass[i][j] |= checkPass(pass, i, j - 1, passed);
    }
    if (pass[i][j] & 0b0000001 && !passed[i][j + 1]) {
        pass[i][j] |= checkPass(pass, i, j + 1, passed);
    }
    return pass[i][j] & 0b110000;
}

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<char>> pass(m, vector<char>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                pass[i][j] =
                    ((i == 0 || j == 0) << 5) +
                    ((i == m - 1 || j == n - 1) << 4) +
                    ((i > 0 && heights[i][j] >= heights[i - 1][j]) << 3) +
                    ((i < m - 1 && heights[i][j] >= heights[i + 1][j]) << 2) +
                    ((j > 0 && heights[i][j] >= heights[i][j - 1]) << 1) +
                    ((j < n - 1 && heights[i][j] >= heights[i][j + 1]) << 0);
            }
        }
        bool** passed = new bool*[m];
        for (bool** x = passed; x < (passed + m); ++x) {
            *x = new bool[n]();
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (bool** x = passed; x < (passed + m); ++x) {
                    memset(*x, 0, n);
                }
                memset(*passed, 0, n);
                checkPass(pass, i, j, passed);
            }
        }
        for (bool** x = passed; x < (passed + m); ++x) {
            delete[] *x;
        }
        delete[] passed;
        vector<vector<int>> ans;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((pass[i][j] & 0b110000) == 0b110000) {
                    ans.push_back(vector<int>{i, j});
                }
            }
        }
        return ans;
    }
};