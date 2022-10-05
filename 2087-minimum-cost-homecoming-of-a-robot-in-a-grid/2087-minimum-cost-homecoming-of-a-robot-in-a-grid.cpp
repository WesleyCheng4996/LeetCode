class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int minr = min(startPos[0], homePos[0]), maxr = max(startPos[0], homePos[0]);
        int minc = min(startPos[1], homePos[1]), maxc = max(startPos[1], homePos[1]);
        return accumulate(rowCosts.begin() + minr, rowCosts.begin() + maxr + 1, 0)
            + accumulate(colCosts.begin() + minc, colCosts.begin() + maxc + 1, 0)
            - rowCosts[startPos[0]]
            - colCosts[startPos[1]];
    }
};