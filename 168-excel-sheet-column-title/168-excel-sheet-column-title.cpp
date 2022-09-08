class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ret = "";
        do {
            ret.push_back((--columnNumber) % 26 + 'A');
            columnNumber /= 26;
        } while (columnNumber);
        reverse(ret.begin(), ret.end());
        return ret;
    }
};