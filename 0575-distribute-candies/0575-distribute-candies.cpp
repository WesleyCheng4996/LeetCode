class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        return min((int)unordered_set<int>(candyType.begin(), candyType.end()).size(), (int)(candyType.size() >> 1));
    }
};