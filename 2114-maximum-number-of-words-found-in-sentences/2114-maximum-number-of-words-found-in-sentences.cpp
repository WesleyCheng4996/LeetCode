class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ret = 0;
        for(string& str : sentences) {
            vector<string> vec;
            int idx;
            while((idx = str.find(' ')) != string::npos) {
                vec.push_back(str.substr(0, idx));
                str.erase(0, idx + 1);
            }
            vec.push_back(str);
            if(ret < vec.size()) {
                ret = vec.size();
            }
        }
        return ret;
    }
};