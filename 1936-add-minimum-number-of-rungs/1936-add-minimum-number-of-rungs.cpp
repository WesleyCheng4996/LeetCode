class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int ret = 0;
        rungs.insert(rungs.begin(), 0);
        for(int i = 1; i < rungs.size(); ++i) {
            ret += ((rungs[i] - rungs[i - 1]) - 1) / dist;
        }
        return ret;
    }
};