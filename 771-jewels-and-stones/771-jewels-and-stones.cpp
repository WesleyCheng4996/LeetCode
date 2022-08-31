class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int ans = 0;
        for(char ch: jewels) {
            ans += count(stones.begin(), stones.end(), ch);
        }
        return ans;
    }
};