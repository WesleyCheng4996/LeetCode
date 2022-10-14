class Solution {
public:
    char findTheDifference(string s, string t) {
        s += t;
        return accumulate(s.begin(), s.end(), 0, [](char sum, char x) { return sum ^ x; });
    }
};