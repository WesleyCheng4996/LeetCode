class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(string s : words) {
            if(isPalindrome(s)) {
                return s;
            }
        }
        return "";
    }
    bool isPalindrome(const string &str) {
        return str == string(str.rbegin(), str.rend());
    }
};