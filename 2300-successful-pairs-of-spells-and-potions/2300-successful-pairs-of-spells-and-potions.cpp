class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>ret;ret.reserve(spells.size());
        sort(potions.begin(), potions.end());
        for(int x : spells) {
            ret.push_back(potions.end() - lower_bound(potions.begin(), potions.end(), (long long)ceil((double)success / x)));
        }
        return ret;
    }
};