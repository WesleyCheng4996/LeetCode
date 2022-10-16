class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
       int ret = 0;
        for(string& x : words) {
            ret += (s.find(x) == 0);
        }
        return ret;
    }
};