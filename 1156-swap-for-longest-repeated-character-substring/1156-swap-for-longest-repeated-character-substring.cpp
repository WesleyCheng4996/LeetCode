class Solution {
public:
    vector<pair<int, char>> compress(const string& s) {
        vector<pair<int, char>>ret;
        for (int i = 0; i < s.size(); ++i) {
            int k = 0;
            char c = s[i];
            while (s[i] == c) {
                ++i;
                ++k;
            }
            --i;
            ret.push_back({ k, c });
        }
        return ret;
    }
    int maxRepOpt1(string text) {
        unordered_map<char, int>count;
        vector<pair<int, char>> comp = compress(text);
        int ret = 0;
        for (int i = 0; i < comp.size(); ++i) {
            ++count[comp[i].second];
        }
        for (int i = 0; i < comp.size(); ++i) {
            ret = max(ret, comp[i].first + (count[comp[i].second] > 1));
            if (comp[i].first == 1) {
                if (i > 0 && i < comp.size() - 1 && comp[i - 1].second == comp[i + 1].second) {
                    ret = max(ret, comp[i - 1].first + comp[i + 1].first + (count[comp[i - 1].second] > 2));
                }
            }
        }
        return ret;
    }
};