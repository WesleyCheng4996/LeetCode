const std::vector<std::string> split(const std::string &str, const char &delimiter) {
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string tok;

    while (std::getline(ss, tok, delimiter)) {
        result.push_back(tok);
    }
    return result;
}

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<string> ss = split(text, ' ');
        int ret = ss.size();
        for (string s : ss) {
            for (char ch : brokenLetters) {
                if (find(s.begin(), s.end(), ch) == s.end()) {
                    continue;
                }
                --ret;
                break;
            }
        }
        return ret;
    }
};