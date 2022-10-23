class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0, minnum = prices[0];
        for(int x : prices) {
            if(minnum > x) {
                minnum = x;
            } else {
                ret = max(ret, x - minnum);
            }
        }
        return ret;
    }
};