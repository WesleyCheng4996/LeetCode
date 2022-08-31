class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int ans = 0;
        string::iterator begin = stones.begin(), end = stones.end();
        for(char ch: jewels) {
            ans += count(begin, end, ch);
        }
        return ans;
    }
};