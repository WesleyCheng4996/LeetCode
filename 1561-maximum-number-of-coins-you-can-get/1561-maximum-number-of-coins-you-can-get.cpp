class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int can_pick_times = piles.size() / 3, ans = 0;
        sort(piles.begin(), piles.end());
        for(int i = can_pick_times; can_pick_times--; i += 2) {
            ans += piles[i];
        }
        return ans;
    }
};