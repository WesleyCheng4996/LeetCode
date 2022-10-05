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
    bool isPalindrome(string str) {
        unsigned int sz = str.size();
        for(int i = (sz >> 1); i >= 0; --i) {
            if(str[i] != str[sz - i - 1]) {
                return false;
            }
        }
        return true;
    }
};