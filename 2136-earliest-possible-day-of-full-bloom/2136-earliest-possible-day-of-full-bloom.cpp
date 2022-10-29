class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int, int>>times;
        for(int i = 0; i < plantTime.size(); ++i) {
            times.push_back({ growTime[i], plantTime[i] });
        }
        sort(times.begin(), times.end());
         int ret = 0;
        for (auto [g, p] : times) {
            ret = max(ret, g) + p;
        }
        return ret;
    }
};