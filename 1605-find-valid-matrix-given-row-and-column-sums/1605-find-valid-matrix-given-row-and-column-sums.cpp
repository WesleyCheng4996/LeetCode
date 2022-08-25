class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSums, vector<int>& colSums) {
        int row = rowSums.size(), col = colSums.size();
        vector<vector<int>> ans(row);
        for(auto& x: ans){
            x.resize(col);
        }
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col && rowSums[i] > 0; ++j){
                if(colSums[j] >= rowSums[i]){
                    colSums[j] -= rowSums[i];
                    ans[i][j] = rowSums[i];
                    rowSums[i] = 0;
                    
                }
                else {
                    rowSums[i] -= colSums[j];
                    ans[i][j] = colSums[j];
                    colSums[j] = 0;
                    
                }
            }
        }
        return ans;
    }
};