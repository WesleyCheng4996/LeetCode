class Solution {
public:
    bool isValid(string str) {
        for(int i = str.find("abc"); i != -1; i = str.find("abc")) {
            str.erase(i, 3);
        }
        return str.empty();
    }
};