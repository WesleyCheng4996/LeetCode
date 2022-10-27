class Solution {
public:
    bool isPalindromic(const string& s) {
        int half_sz = s.size() >> 1;
        for(int i = 0; i < half_sz; ++i) {
            if(s[i] != s[s.size() - i - 1]) {
                return false;
            }
        }
        return true;
    }
    string longestPalindrome(string s) {
        string ret = s.substr(0, 1);
        for(int i = 0; i < s.size(); ++i) {
            string substr = s.substr(i, s.size() - i);
            while(substr.size() > ret.size()) {
                if(substr[0] == substr.back() && isPalindromic(substr)) {
                    ret = substr;
                    break;
                }
                substr.pop_back();
            }
        }
        return ret;
    }
};

static auto s = ios_base::sync_with_stdio(false);
static auto ss = cin.tie(nullptr);
static auto sss = cout.tie(nullptr);