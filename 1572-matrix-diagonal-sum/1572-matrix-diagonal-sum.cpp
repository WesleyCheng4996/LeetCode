class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ret = 0;
        for(int i = 0, end = mat.size(); i < end; ++i) {
            ret += ((i << 1) == end - 1 ? mat[i][i] : mat[i][i] + mat[i][end - i - 1]);
        }
        return ret;
    }
};