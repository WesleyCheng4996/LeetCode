class Solution {
public:
    map<string, int> mp{{"type", 0}, {"color", 1}, {"name", 2}};
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int x = mp[ruleKey];
        unordered_map<string, int>count;
        for(vector<string>& item : items) {
            ++count[item[x]];
        }
        return count[ruleValue];
    }
};

static auto s = ios_base::sync_with_stdio(false);
static auto ss = cin.tie(nullptr);
static auto sss = cout.tie(nullptr);