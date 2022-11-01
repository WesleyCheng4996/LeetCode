class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int>ret;
        for(int j = 0; j < grid[0].size(); ++j) {
            int location = j;
            for(int i = 0; i < grid.size(); ++i) {
                if(grid[i][location] == 1) {
                    if(location + 1 < grid[0].size() && grid[i][location + 1] == 1) {
                        ++location;
                    } else {
                        ret.push_back(-1);
                        break;
                    }
                } else {
                    if(location - 1 >= 0 && grid[i][location - 1] == -1) {
                        --location;
                    } else {
                        ret.push_back(-1);
                        break;
                    }
                }
            }
            if(ret.size() == j) {
                ret.push_back(location);
            }
        }
        return ret;
    }
};