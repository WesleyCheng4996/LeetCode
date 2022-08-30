class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m(matrix.size()), n(matrix[0].size());
        vector<vector<int>>ans(m, vector<int>(n));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                ans[i][j] = matrix[n - j - 1][i];
            }
        }
        matrix.swap(ans);
    }
};