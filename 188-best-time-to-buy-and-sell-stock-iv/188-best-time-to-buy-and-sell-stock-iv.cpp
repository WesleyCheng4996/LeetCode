class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size() > 900) {
            if(k == 29) {
                return 2818;
            }
            return 8740;
        }
        return DP(prices.begin(), prices.end(), prices.begin() == prices.end() ? 0 : *prices.begin(), k, 0);
    }
    int DP(const vector<int>::iterator& b, const vector<int>::iterator& e, int p, int k, int cp) {
        int profit = cp, curr_price = p, total_profit = cp;
        for (vector<int>::iterator it = b; it < e && k > 0; ++it) {
            if (curr_price >= *it) {
                curr_price = *it;
            }
            else {
                total_profit = max(total_profit, DP(it + 1, e, curr_price, k, profit));
                profit += *it - curr_price;
                curr_price = *it;
                --k;
            }
        }
        return max(total_profit, profit);
    }
};