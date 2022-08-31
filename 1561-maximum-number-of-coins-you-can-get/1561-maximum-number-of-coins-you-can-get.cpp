class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int ans = 0;
        sort(piles.begin(), piles.end());
        for(int i = piles.size() / 3, end = piles.size(); i < end; i += 2) {
            ans += piles[i];
        }
        return ans;
    }
};