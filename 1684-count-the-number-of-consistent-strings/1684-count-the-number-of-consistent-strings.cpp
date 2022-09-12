class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ret = 0;
        sort(allowed.begin(), allowed.end());
        for(auto &str: words) {
            ret += check(allowed, str);
        }
        return ret;
    }
    int check(const string& allowed, const string& str) {
        for(auto &x: str) {
            if(binary_search(allowed.begin(), allowed.end(), x) == false) {
                return 0;
            }
        }
        return 1;
    }
};