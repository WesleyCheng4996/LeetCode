class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int>mp;
        bool b = true;
        int ret = 0;
        for(string& word : words) {
            ++mp[word];
        }
        for(auto& [word, times] : mp) {
            string reword{ word[1], word[0] };
            if(word == reword) {
                ret += (times >> 1) << 1;
                if(b && (times & 1)) {
                    ++ret;
                    b = false;
                }
            } else if(mp.count(reword)) {
                ret += min(times, mp[reword]);
            }
        }
        return ret << 1;
    }
};

static auto s = ios_base::sync_with_stdio(false);
static auto ss = cin.tie(nullptr);
static auto sss = cout.tie(nullptr);