class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<pair<int, string>>vec;
        unordered_map<string, int> mp;
        for(int i = 0; i < words.size(); ++i) {
            if(mp.count(words[i]) == 0) {
                mp[words[i]] = vec.size();
                vec.push_back(pair<int, string>{1, words[i]});
            } else {
                ++vec[mp[words[i]]].first;
            }
        }
        sort(vec.begin(), vec.end(), [](pair<int, string>a, pair<int, string>b){return a.first > b.first || (a.first == b.first && a.second < b.second);});
        vector<string>ret;
        for(int i = 0; i < k; ++i) {
            ret.push_back(vec[i].second);
        }
        return ret;
    }
};