class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        return accumulate(words.begin(), words.end(), 0, [&](int sum, string& str) { return sum + (str.find(pref) == 0); });
    }
};