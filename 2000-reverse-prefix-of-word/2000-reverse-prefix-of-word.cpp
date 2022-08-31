class Solution {
public:
    string reversePrefix(string word, char ch) {
        auto begin = word.begin();
        reverse(begin, ++begin + word.find(ch));
        return word;
    }
};