class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return unordered_set<int>(nums.begin(), nums.end()).size() != nums.size(); 
    }
};
static auto s = ios_base::sync_with_stdio(false);
static auto ss = cin.tie(nullptr);