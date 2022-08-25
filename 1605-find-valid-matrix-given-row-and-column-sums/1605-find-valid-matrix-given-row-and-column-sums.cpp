class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSums, vector<int>& colSums) {
        int row = rowSums.size(), col = colSums.size();
        vector<vector<int>> ans(row);
        for(auto& x: ans){
            x.resize(col);
        }
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j){
                if(colSums[j] >= rowSums[i]){
                    ans[i][j] = rowSums[i];
                    colSums[j] -= rowSums[i];
                    rowSums[i] = 0;
                    break;
                }
                else {
                    ans[i][j] = colSums[j];
                    rowSums[i] -= colSums[j];
                    colSums[j] = 0;
                }
            }
        }
        return ans;
    }
};