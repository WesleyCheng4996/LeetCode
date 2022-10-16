class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        return accumulate(words.begin(), words.end(), 0, [&](int sum, string& x) { return sum + (s.find(x) == 0); });
    }
};