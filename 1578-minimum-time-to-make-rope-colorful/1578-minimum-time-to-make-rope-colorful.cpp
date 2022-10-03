class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ret = 0;
        for(int i = 0, end = colors.size() - 1; i < end; ++i) {
            if(colors[i] == colors[i + 1]) {
                int max_val = neededTime[i];
                ret += neededTime[i];
                do {
                    ++i;
                    if(neededTime[i] > max_val) {
                        max_val = neededTime[i];
                    }
                    ret += neededTime[i];
                } while(colors[i] == colors[i + 1]);
                ret -= max_val;
            }
        }
        return ret;
    }
};