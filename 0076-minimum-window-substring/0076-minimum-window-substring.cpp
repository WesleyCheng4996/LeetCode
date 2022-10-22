class Solution {
public:
bool all_find(unordered_map<char, int>& mp) {
    for (auto x : mp) {
        if (x.second > 0) {
            return false;
        }
    }
    return true;
}
string minWindow(string s, string t) {
    unordered_map<char, int>mp;
    for (char c : t) {
        ++mp[c];
    }
    string ret = "";
    int idx1 = 0, idx2 = 0;
    while (idx2 < s.size()) {
        if (mp.count(s[idx2])) {
            --mp[s[idx2]];
            if (all_find(mp)) {
                break;
            }
        }
        ++idx2;
    }
    ++idx2;
    if (!all_find(mp)) {
        return "";
    }
    ret = s;
    while (idx2 < s.size()) {
        while (idx1 < s.size()) {
            if (mp.count(s[idx1])) {
                ++mp[s[idx1]];
                if (!all_find(mp)) {
                    break;
                }
            }
            ++idx1;
        }
        --mp[s[idx1]];
        ret = (all_find(mp) && ret.size() > (idx2 - idx1)) ? s.substr(idx1, idx2 - idx1) : ret;
        ++mp[s[idx1++]];
        while (idx2 < s.size()) {
            if (mp.count(s[idx2])) {
                --mp[s[idx2]];
                if (all_find(mp)) {
                    break;
                }
            }
            ++idx2;
        }
        ++idx2;
        ret = (all_find(mp) && ret.size() > (idx2 - idx1)) ? s.substr(idx1, idx2 - idx1) : ret;
    }
    while (idx1 < s.size()) {
        if (mp.count(s[idx1])) {
            ++mp[s[idx1]];
            if (!all_find(mp)) {
                break;
            }
        }
        ++idx1;
    }
    --mp[s[idx1]];
    ret = (all_find(mp) && ret.size() > (idx2 - idx1)) ? s.substr(idx1, idx2 - idx1) : ret;
    return ret;
}
};