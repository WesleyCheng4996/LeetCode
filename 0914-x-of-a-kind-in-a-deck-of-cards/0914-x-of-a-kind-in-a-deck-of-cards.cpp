class Solution {
public:
    int GCD(int a, int b) {
        return b == 0 ? a : GCD(b, a % b);
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        if(deck.size() == 1) {
            return false;
        }
        unordered_map<int, int>count;
        for(int x : deck) {
            ++count[x];
        }
        return (accumulate(count.begin(), count.end(), count.begin()->second, [&](int sum, auto p){ return GCD(sum, p.second); }) > 1);
    }
};