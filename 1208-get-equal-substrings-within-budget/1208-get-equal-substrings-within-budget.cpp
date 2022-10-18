class Solution {
public:

    int equalSubstring(string s, string t, int maxCost) {
        vector<int>cost(s.size());
        for (int i = 0; i < s.size(); ++i) {
            cost[i] = abs(s[i] - t[i]);
        }
        for(int i = 1; i < s.size(); ++i) {
            cost[i] += cost[i - 1];
        }
        int ret = 0;
        cost.insert(cost.begin(), 0);
        for(int i = 1; i < s.size(); ++i) {
            int len = upper_bound(cost.begin() + i, cost.end(), maxCost + cost[i - 1]) - cost.begin() - i;
            ret = len > ret ? len : ret;
        }
        return ret;
    }
};