class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        s[max(0, (int)s.find('6'))] = '9';
        return stoi(s);
    }
};