class Solution {
public:
    const std::vector<std::string> split(const std::string& str, const std::string& pattern) {
        std::vector<std::string> result;
        std::string::size_type begin, end;

        end = str.find(pattern);
        begin = 0;

        while (end != std::string::npos) {
            if (end - begin != 0) {
                result.push_back(str.substr(begin, end-begin)); 
            }    
            begin = end + pattern.size();
            end = str.find(pattern, begin);
        }

        if (begin != str.length()) {
            result.push_back(str.substr(begin));
        }
        return result;        
    }
    int isPrefixOfWord(string sentence, string searchWord) {
        const vector<string>sp = split(sentence, " ");
        for(int i = 0; i < sp.size(); ++i) {
            if(sp[i].find(searchWord) == 0) {
                return i + 1;
            }
        }
        return -1;
    }
};