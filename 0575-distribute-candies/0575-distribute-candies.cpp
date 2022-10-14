class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        return min((int)unordered_set<int>(candyType.begin(), candyType.end()).size(), (int)(candyType.size() >> 1));
    }
};
static auto s = ios_base::sync_with_stdio(false);
static auto ss = cin.tie(nullptr);