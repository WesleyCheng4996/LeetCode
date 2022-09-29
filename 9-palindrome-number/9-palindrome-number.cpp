class Solution {
public:
    bool isPalindrome(int x) {
        string num = to_string(x);
        string::iterator it = num.begin(), itt = num.end() - 1;
        while(it < itt) {
            if(*it++ != *itt--) {
                return false;
            }
        }
        return true;
    }
};