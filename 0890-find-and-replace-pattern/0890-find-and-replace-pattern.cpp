class Solution {
    bool compare(int* dst, int* src, int count) {
        for(int i = 0; i < count; ++i) {
            if(dst[i] != src[i])
                return false;
        }
        return true;
    }
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ret;
        unordered_map<char, int>mp;
        int com[50] = { 0 };
        for(int i = 0; i < pattern.size(); ++i) {
            if(mp.count(pattern[i]) == 0) {
                mp[pattern[i]] = mp.size();
            }
            com[i] = mp[pattern[i]];
        }
        mp.clear();
        for(string& word : words) {
            int temp[50] = { 0 };
            for(int i = 0; i < word.size(); ++i) {
                if(mp.count(word[i]) == 0) {
                    mp[word[i]] = mp.size();
                }
                temp[i] = mp[word[i]];
            }
            mp.clear();

            if(compare(com, temp, 26)) {
                ret.push_back(word);
            }
        }
        return ret;
    }
};