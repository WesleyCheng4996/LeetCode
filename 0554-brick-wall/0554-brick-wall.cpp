class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> count;
        for(vector<int> row : wall) {
            int k = 0;
            for(int i = 0, end = row.size() - 1; i < end; ++i) {
                ++count[k += row[i]];
            }
        }
        int ma = 0;
        for(auto & [key, val] : count) {
            ma = max(ma, val);
        }
        return wall.size() - ma;
    }
};