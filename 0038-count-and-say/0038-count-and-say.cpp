

class Solution {
public:
    string func(const string& str) {
        string ret = "";
        for(int i = 0; i < str.size(); ++i) {
            char c = str[i];
            int count = 1;
            while(i + 1 < str.size() && str[i + 1] == c) {
                ++i;
                ++count;
            }
            ret.insert(ret.size(), to_string(count));
            ret.push_back(c);
        }
        return ret;
    }
    string countAndSay(int n) {
        string ret ="1";
        while(--n) {
            ret = func(ret);
        }
        return ret;
    }
};