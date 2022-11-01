class Solution {
public:
    vector<string> split(string s, char c) {
        vector<string>ret;
        while(s.find(c) != string::npos) {
            ret.push_back(s.substr(0, s.find(c)));
            s.erase(0, s.find(c) + 1);
        }
        ret.push_back(s);
        return ret;
    }
    string sortSentence(string s) {
        string ret = "";
        vector<string> ss = split(s, ' ');
        sort(ss.begin(), ss.end(), [](string s, string ss) { return s.back() < ss.back(); });
        for(string str : ss) {
            str.pop_back();
            ret += str + " ";
        }
        ret.pop_back();
        return ret;
    }
};