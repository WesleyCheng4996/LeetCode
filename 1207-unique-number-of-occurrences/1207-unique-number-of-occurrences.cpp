class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int c[2001] = { 0 };
        for(int x: arr) {
            ++c[x + 1000];
        }
        sort(c, c + 2001);
        for(int i = 0; i < 2000; ++i) {
            if(c[i] == c[i + 1] && c[i] != 0) {
                return false;
            }
        }
        return true;
    }
};